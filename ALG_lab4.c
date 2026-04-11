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


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char buf[1024];
    printf("Vvedite translit: ");
    fgets(buf, sizeof(buf), stdin);

    int i = 0;
    while (buf[i] != '\0') {
        // Проверяем комбинации (жадный поиск: сначала длинные)
        
        // 3 буквы
        if (strncmp(&buf[i], "sch", 3) == 0 || strncmp(&buf[i], "Sch", 3) == 0) {
            printf("щ"); i += 3; continue;
        }
        
        // 2 буквы
        if (strncmp(&buf[i], "zh", 2) == 0 || strncmp(&buf[i], "Zh", 2) == 0) { printf("ж"); i += 2; continue; }
        if (strncmp(&buf[i], "ch", 2) == 0 || strncmp(&buf[i], "Ch", 2) == 0) { printf("ч"); i += 2; continue; }
        if (strncmp(&buf[i], "sh", 2) == 0 || strncmp(&buf[i], "Sh", 2) == 0) { printf("ш"); i += 2; continue; }
        if (strncmp(&buf[i], "yo", 2) == 0 || strncmp(&buf[i], "Yo", 2) == 0) { printf("ё"); i += 2; continue; }
        if (strncmp(&buf[i], "yu", 2) == 0 || strncmp(&buf[i], "Yu", 2) == 0) { printf("ю"); i += 2; continue; }
        if (strncmp(&buf[i], "ya", 2) == 0 || strncmp(&buf[i], "Ya", 2) == 0) { printf("я"); i += 2; continue; }
        if (strncmp(&buf[i], "kh", 2) == 0 || strncmp(&buf[i], "Kh", 2) == 0) { printf("х"); i += 2; continue; }
        if (strncmp(&buf[i], "ts", 2) == 0 || strncmp(&buf[i], "Ts", 2) == 0) { printf("ц"); i += 2; continue; }

        // 1 буква (строчные)
        char c = buf[i];
        switch (tolower(c)) {
            case 'a': printf("а"); break;
            case 'b': printf("б"); break;
            case 'v': printf("в"); break;
            case 'g': printf("г"); break;
            case 'd': printf("д"); break;
            case 'e': printf("е"); break;
            case 'z': printf("з"); break;
            case 'i': printf("и"); break;
            case 'j': printf("й"); break; // или j->дж, но пусть будет й для простоты
            case 'k': printf("к"); break;
            case 'l': printf("л"); break;
            case 'm': printf("м"); break;
            case 'n': printf("н"); break;
            case 'o': printf("о"); break;
            case 'p': printf("п"); break;
            case 'r': printf("р"); break;
            case 's': printf("с"); break;
            case 't': printf("т"); break;
            case 'u': printf("у"); break;
            case 'f': printf("ф"); break;
            case 'h': printf("х"); break; // если не kh, то h->х (упрощение)
            case 'y': printf("ы"); break; // упрощение: y->ы. (йо будет yo)
            case '\'': printf("ь"); break;
            case '"': printf("ъ"); break;
            default: putchar(c); break; // Пробелы, знаки препинания
        }
        i++;
    }
    return 0;
}
