#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    const char *rus;
    const char *lat;
} TranslitPair;

// Полная таблица: строчные и заглавные буквы
static const TranslitPair translit_table[] = {
    // Строчные
    {"а", "a"}, {"б", "b"}, {"в", "v"}, {"г", "g"}, {"д", "d"},
    {"е", "e"}, {"ё", "yo"}, {"ж", "zh"}, {"з", "z"}, {"и", "i"},
    {"й", "y"}, {"к", "k"}, {"л", "l"}, {"м", "m"}, {"н", "n"},
    {"о", "o"}, {"п", "p"}, {"р", "r"}, {"с", "s"}, {"т", "t"},
    {"у", "u"}, {"ф", "f"}, {"х", "kh"}, {"ц", "ts"}, {"ч", "ch"},
    {"ш", "sh"}, {"щ", "sch"}, {"ъ", "\""}, {"ы", "y"}, {"ь", "'"},
    {"э", "e"}, {"ю", "yu"}, {"я", "ya"},
    // Заглавные
    {"А", "A"}, {"Б", "B"}, {"В", "V"}, {"Г", "G"}, {"Д", "D"},
    {"Е", "E"}, {"Ё", "Yo"}, {"Ж", "Zh"}, {"З", "Z"}, {"И", "I"},
    {"Й", "Y"}, {"К", "K"}, {"Л", "L"}, {"М", "M"}, {"Н", "N"},
    {"О", "O"}, {"П", "P"}, {"Р", "R"}, {"С", "S"}, {"Т", "T"},
    {"У", "U"}, {"Ф", "F"}, {"Х", "Kh"}, {"Ц", "Ts"}, {"Ч", "Ch"},
    {"Ш", "Sh"}, {"Щ", "Sch"}, {"Ъ", "\""}, {"Ы", "Y"}, {"Ь", "'"},
    {"Э", "E"}, {"Ю", "Yu"}, {"Я", "Ya"}
};

#define TABLE_SIZE (sizeof(translit_table) / sizeof(translit_table[0]))

int main() {
    char input[1024];
    char output[4096] = {0};

    printf("Введите русский текст:\n");
    if (!fgets(input, sizeof(input), stdin)) {
        return 1;
    }

    // Убираем символ новой строки
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    int out_pos = 0;
    int i = 0;

    while (input[i] != '\0') {
        unsigned char c = (unsigned char)input[i];

        if (c < 0x80) {
            // ASCII-символ
            output[out_pos++] = input[i];
            i++;
        } else if ((c & 0xE0) == 0xC0) {
            // Двухбайтовый UTF-8 символ (русские буквы)
            char rus_char[3] = {input[i], input[i + 1], '\0'};
            int found = 0;

            for (size_t j = 0; j < TABLE_SIZE; j++) {
                if (strcmp(rus_char, translit_table[j].rus) == 0) {
                    const char *lat = translit_table[j].lat;
                    int lat_len = strlen(lat);
                    strncpy(&output[out_pos], lat, lat_len);
                    out_pos += lat_len;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                // Если не нашли в таблице, копируем как есть
                output[out_pos++] = input[i];
                output[out_pos++] = input[i + 1];
            }
            i += 2;
        } else {
            // Другие многобайтовые символы или неверная кодировка
            output[out_pos++] = input[i];
            i++;
        }
    }

    output[out_pos] = '\0';
    printf("Транслитерация:\n%s\n", output);

    return 0;
}
