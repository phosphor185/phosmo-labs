int segments_intersect(SEGMENT s1, SEGMENT s2) {
    #define CP(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
    double a1 = CP(s1.x2-s1.x1, s1.y2-s1.y1, s2.x1-s1.x1, s2.y1-s1.y1);
    double a2 = CP(s1.x2-s1.x1, s1.y2-s1.y1, s2.x2-s1.x1, s2.y2-s1.y1);
    double a3 = CP(s2.x2-s2.x1, s2.y2-s2.y1, s1.x1-s2.x1, s1.y1-s2.y1);
    double a4 = CP(s2.x2-s2.x1, s2.y2-s2.y1, s1.x2-s2.x1, s1.y2-s2.y1);
    #undef CP
    return (a1*a2 < 0) && (a3*a4 < 0);
}
