/*** "ascii_8.cpp" ***/
static const struct
{
    unsigned char height;
    unsigned char widths[95];
    const char* u8_pixel_data[95];
}
ascii_chars = 
{
    8, // height

    { // widths
        5, 3, 5, 7, 6, 7, 7, 3, 6, 6, 5, 7, 4, 6, 4, 5, 5, 6, 6, 6, 5, 5, 5, 5, 5, 5, 3, 4, 5, 6, 5, 6, 7, 5, 6, 6, 6, 5, 5, 7, 6, 6, 6, 6, 6, 7, 8, 7, 6, 7, 6, 6, 6, 6, 6, 8, 6, 6, 6, 5, 5, 5, 5, 6, 4, 5, 5, 5, 5, 5, 5, 5, 5, 3, 4, 4, 3, 6, 5, 5, 5, 6, 5, 5, 4, 6, 6, 6, 6, 6, 6, 5, 3, 5, 6, 
    },

    { // u8_pixel_data
        /* ' ' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
        /* '!' */ "\0\0\0\0\1\0\0\1\0\0\1\0\0\1\0\0\1\0\0\0\0\0\1\0",
        /* '"' */ "\0\1\0\1\0\0\1\0\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
        /* '#' */ "\0\0\0\0\0\0\0\0\1\0\0\1\0\0\1\1\1\1\1\1\0\0\1\0\0\1\0\0\0\1\0\0\1\0\0\1\1\1\1\1\1\0\0\1\0\0\1\0\0\0\0\0\0\0\0\0",
        /* '$' */ "\0\0\0\0\0\0\0\0\1\0\0\0\0\1\1\1\1\0\1\0\1\0\0\0\0\1\1\1\0\0\0\0\1\0\1\0\1\1\1\1\0\0\0\0\1\0\0\0",
        /* '%' */ "\0\0\0\0\0\0\0\1\1\0\0\0\1\0\1\1\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\1\1\0\1\0\0\0\1\1\0\0\0\0\0\0\0\0",
        /* '&' */ "\0\0\1\1\0\0\0\0\1\0\0\1\0\0\0\0\1\1\0\0\0\0\1\0\0\0\0\0\1\0\1\0\0\1\0\1\0\0\1\0\1\0\0\1\0\0\1\0\0\0\0\1\1\0\1\0",
        /* ''' */ "\0\1\0\0\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
        /* '(' */ "\0\0\0\1\1\0\0\0\1\0\0\0\0\0\1\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\0\1\1\0",
        /* ')' */ "\0\1\1\0\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\1\0\0\0\0\0\1\0\0\0\1\1\0\0\0",
        /* '*' */ "\0\0\0\0\0\0\1\0\1\0\0\0\1\0\0\0\1\0\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
        /* '+' */ "\0\0\0\0\0\0\0\0\0\0\1\0\0\0\0\0\0\1\0\0\0\0\1\1\1\1\1\0\0\0\0\1\0\0\0\0\0\0\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
        /* ',' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\0\0\0\1\0\0\1\0\0",
        /* '-' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\1\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
        /* '.' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\0\0\1\1\0",
        /* '/' */ "\0\0\0\1\0\0\0\0\1\0\0\0\1\0\0\0\0\1\0\0\0\1\0\0\0\0\1\0\0\0\1\0\0\0\0\1\0\0\0\0",
        /* '0' */ "\0\0\0\0\0\0\1\1\0\0\1\0\0\1\0\1\0\0\1\0\1\0\0\1\0\1\0\0\1\0\1\0\0\1\0\0\1\1\0\0",
        /* '1' */ "\0\0\0\0\0\0\0\0\1\0\0\0\0\1\1\0\0\0\1\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\1\1\1\1\1\0",
        /* '2' */ "\0\0\0\0\0\0\0\1\1\1\0\0\1\0\0\0\1\0\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\1\1\1\1\0",
        /* '3' */ "\0\0\0\0\0\0\0\1\1\1\0\0\1\0\0\0\1\0\0\0\0\0\1\0\0\0\1\1\0\0\0\0\0\0\1\0\1\0\0\0\1\0\0\1\1\1\0\0",
        /* '4' */ "\0\0\0\0\0\1\0\0\1\0\1\0\0\1\0\1\0\0\1\0\1\1\1\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0",
        /* '5' */ "\0\0\0\0\0\1\1\1\1\0\1\0\0\0\0\1\1\1\0\0\0\0\0\1\0\0\0\0\1\0\1\0\0\1\0\0\1\1\0\0",
        /* '6' */ "\0\0\0\0\0\0\1\1\0\0\1\0\0\1\0\1\0\0\0\0\1\1\1\0\0\1\0\0\1\0\1\0\0\1\0\0\1\1\0\0",
        /* '7' */ "\0\0\0\0\0\1\1\1\1\0\0\0\0\1\0\0\0\0\1\0\0\0\1\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0",
        /* '8' */ "\0\0\0\0\0\0\1\1\0\0\1\0\0\1\0\1\0\0\1\0\0\1\1\0\0\1\0\0\1\0\1\0\0\1\0\0\1\1\0\0",
        /* '9' */ "\0\0\0\0\0\0\1\1\0\0\1\0\0\1\0\1\0\0\1\0\0\1\1\1\0\0\0\0\1\0\1\0\0\1\0\0\1\1\0\0",
        /* ':' */ "\0\0\0\0\0\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\0\0",
        /* ';' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\0\0\0\0\0\0\0\1\0\0\0\1\0\0\1\0\0",
        /* '<' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\1\0\0\0\1\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\0",
        /* '=' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\1\1\0\0\0\0\0\0\0\0\1\1\1\1\0\0\0\0\0\0\0\0\0\0\0\0\0",
        /* '>' */ "\0\0\0\0\0\0\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\1\0\0\0\1\0\0\0\0\0\0\0\0",
        /* '?' */ "\0\0\0\0\0\0\0\1\1\1\0\0\1\0\0\0\1\0\0\0\0\0\1\0\0\0\1\1\0\0\0\0\1\0\0\0\0\0\0\0\0\0\0\0\1\0\0\0",
        /* '@' */ "\0\0\1\1\1\0\0\0\1\0\0\0\1\0\1\0\0\1\0\0\1\1\0\1\0\1\0\1\1\0\1\0\1\0\1\1\0\0\1\1\0\1\0\1\0\0\1\1\0\0\0\1\0\0\0\0",
        /* 'A' */ "\0\0\0\0\0\0\1\1\0\0\1\0\0\1\0\1\0\0\1\0\1\1\1\1\0\1\0\0\1\0\1\0\0\1\0\1\0\0\1\0",
        /* 'B' */ "\0\0\0\0\0\0\1\1\1\1\0\0\1\0\0\0\1\0\1\0\0\0\1\0\1\1\1\1\0\0\1\0\0\0\1\0\1\0\0\0\1\0\1\1\1\1\0\0",
        /* 'C' */ "\0\0\0\0\0\0\0\1\1\1\0\0\1\0\0\0\1\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\1\0\0\1\1\1\0\0",
        /* 'D' */ "\0\0\0\0\0\0\1\1\1\1\0\0\1\0\0\0\1\0\1\0\0\0\1\0\1\0\0\0\1\0\1\0\0\0\1\0\1\0\0\0\1\0\1\1\1\1\0\0",
        /* 'E' */ "\0\0\0\0\0\1\1\1\1\0\1\0\0\0\0\1\0\0\0\0\1\1\1\0\0\1\0\0\0\0\1\0\0\0\0\1\1\1\1\0",
        /* 'F' */ "\0\0\0\0\0\1\1\1\1\0\1\0\0\0\0\1\0\0\0\0\1\1\1\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0",
        /* 'G' */ "\0\0\0\0\0\0\0\0\1\1\1\1\0\0\1\0\0\0\0\1\0\1\0\0\0\0\0\0\1\0\0\1\1\1\0\1\0\0\0\0\1\0\1\0\0\0\0\1\0\0\1\1\1\1\0\0",
        /* 'H' */ "\0\0\0\0\0\0\1\0\0\0\1\0\1\0\0\0\1\0\1\0\0\0\1\0\1\1\1\1\1\0\1\0\0\0\1\0\1\0\0\0\1\0\1\0\0\0\1\0",
        /* 'I' */ "\0\0\0\0\0\0\1\1\1\1\1\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\1\1\1\1\1\0",
        /* 'J' */ "\0\0\0\0\0\0\0\1\1\1\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\1\0\0\0\1\0\0\1\1\1\0\0",
        /* 'K' */ "\0\0\0\0\0\0\1\0\0\0\1\0\1\0\0\1\0\0\1\0\1\0\0\0\1\1\0\0\0\0\1\0\1\1\0\0\1\0\0\0\1\0\1\0\0\0\1\0",
        /* 'L' */ "\0\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\1\1\1\1\0",
        /* 'M' */ "\0\0\0\0\0\0\0\1\0\0\0\0\0\1\1\1\0\0\0\1\1\1\0\1\0\1\0\1\1\0\0\1\0\0\1\1\0\0\0\0\0\1\1\0\0\0\0\0\1\1\0\0\0\0\0\1",
        /* 'N' */ "\0\0\0\0\0\0\0\0\1\0\0\0\0\0\1\0\1\1\0\0\0\0\1\0\1\0\1\0\0\0\1\0\1\0\0\1\0\0\1\0\1\0\0\0\1\0\1\0\1\0\0\0\0\1\1\0\1\0\0\0\0\0\1\0",
        /* 'O' */ "\0\0\0\0\0\0\0\0\1\1\1\1\0\0\1\0\0\0\0\1\0\1\0\0\0\0\1\0\1\0\0\0\0\1\0\1\0\0\0\0\1\0\1\0\0\0\0\1\0\0\1\1\1\1\0\0",
        /* 'P' */ "\0\0\0\0\0\0\1\1\1\1\0\0\1\0\0\0\1\0\1\0\0\0\1\0\1\1\1\1\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0",
        /* 'Q' */ "\0\1\1\1\1\0\0\1\0\0\0\0\1\0\1\0\0\0\0\1\0\1\0\0\0\0\1\0\1\0\0\0\0\1\0\1\0\0\0\0\1\0\0\1\1\1\1\0\0\0\0\0\0\0\1\0",
        /* 'R' */ "\0\0\0\0\0\0\1\1\1\1\0\0\1\0\0\0\1\0\1\0\0\0\1\0\1\1\1\1\0\0\1\0\0\1\0\0\1\0\0\0\1\0\1\0\0\0\1\0",
        /* 'S' */ "\0\0\0\0\0\0\0\1\1\1\0\0\1\0\0\0\1\0\1\0\0\0\0\0\0\1\1\1\0\0\0\0\0\0\1\0\1\0\0\0\1\0\0\1\1\1\0\0",
        /* 'T' */ "\0\0\0\0\0\0\1\1\1\1\1\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0",
        /* 'U' */ "\0\0\0\0\0\0\1\0\0\0\1\0\1\0\0\0\1\0\1\0\0\0\1\0\1\0\0\0\1\0\1\0\0\0\1\0\1\0\0\0\1\0\0\1\1\1\0\0",
        /* 'V' */ "\0\0\0\0\0\0\0\0\0\0\0\0\1\0\0\0\1\0\1\0\0\0\1\0\1\0\0\0\1\0\0\1\0\1\0\0\0\1\0\1\0\0\0\0\1\0\0\0",
        /* 'W' */ "\0\0\0\0\0\0\0\0\1\0\0\0\0\0\1\0\1\0\0\0\0\0\1\0\1\0\0\0\0\0\1\0\0\1\0\1\0\1\0\0\0\1\0\1\0\1\0\0\0\0\1\0\1\0\0\0\0\0\1\0\1\0\0\0",
        /* 'X' */ "\0\0\0\0\0\0\1\0\0\0\1\0\1\0\0\0\1\0\0\1\0\1\0\0\0\0\1\0\0\0\0\1\0\1\0\0\1\0\0\0\1\0\1\0\0\0\1\0",
        /* 'Y' */ "\0\0\0\0\0\0\1\0\0\0\1\0\1\0\0\0\1\0\0\1\0\1\0\0\0\1\1\1\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\0\1\0\0\0",
        /* 'Z' */ "\0\0\0\0\0\0\1\1\1\1\1\0\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\0\1\1\1\1\1\0",
        /* '[' */ "\0\1\1\1\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\1\1\0",
        /* '\' */ "\1\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\1\0\0\0\0\0\1\0\0\0\0\1\0",
        /* ']' */ "\0\1\1\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\1\1\1\0",
        /* '^' */ "\0\0\0\0\0\0\0\1\0\0\0\1\0\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
        /* '_' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\1\1\1\0",
        /* '`' */ "\0\1\0\0\0\0\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
        /* 'a' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\0\0\1\0\0\1\0\1\0\0\1\0\0\1\1\1\0\0\0\0\1\0",
        /* 'b' */ "\0\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\1\1\0\0\1\0\0\1\0\1\0\0\1\0\1\1\1\0\0",
        /* 'c' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\1\0\1\0\0\0\0\1\0\0\0\0\0\1\1\1\0",
        /* 'd' */ "\0\0\0\0\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\1\1\1\0\1\0\0\1\0\1\0\0\1\0\0\1\1\1\0",
        /* 'e' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\0\0\1\0\0\1\0\1\1\1\0\0\1\0\0\0\0\0\1\1\1\0",
        /* 'f' */ "\0\0\0\0\0\0\0\0\0\0\0\1\1\1\0\0\1\0\0\0\0\1\0\0\0\1\1\1\0\0\0\1\0\0\0\0\1\0\0\0",
        /* 'g' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\0\0\1\0\0\1\0\0\1\1\1\0\0\0\0\1\0\0\1\1\1\0",
        /* 'h' */ "\0\0\0\0\0\0\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\1\1\0\0\1\0\0\1\0\1\0\0\1\0",
        /* 'i' */ "\0\0\0\0\0\0\0\0\0\0\1\0\0\0\0\0\1\0\0\1\0\0\1\0",
        /* 'j' */ "\0\0\0\0\0\0\0\0\0\0\1\0\0\0\0\0\0\0\1\0\0\0\1\0\0\0\1\0\1\1\0\0",
        /* 'k' */ "\0\0\0\0\0\0\0\0\1\0\0\0\1\0\0\0\1\0\1\0\1\1\0\0\1\0\1\0\1\0\1\0",
        /* 'l' */ "\0\0\0\0\0\0\0\1\0\0\1\0\0\1\0\0\1\0\0\1\0\0\1\0",
        /* 'm' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\0\0\0\0\0\1\1\0\1\1\0\1\0\1\0\1\0\1\0\0\0\1\0",
        /* 'n' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\0\0\0\0\1\1\1\0\0\1\0\0\1\0\1\0\0\1\0",
        /* 'o' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\0\0\1\0\0\1\0\1\0\0\1\0\0\1\1\0\0",
        /* 'p' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\0\0\1\0\0\1\0\1\1\1\0\0\1\0\0\0\0\1\0\0\0\0",
        /* 'q' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\0\0\0\1\0\0\1\0\0\0\1\1\1\0\0\0\0\0\1\0\0\0\0\0\1\1\0",
        /* 'r' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\0\0\0\0\1\1\1\0\0\1\0\0\1\0\1\0\0\0\0",
        /* 's' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\1\0\1\0\0\0\0\0\1\1\0\0\0\0\0\1\0\1\1\1\0\0",
        /* 't' */ "\0\0\0\0\0\0\0\0\0\1\0\0\0\1\0\0\1\1\1\0\0\1\0\0\0\1\0\0\0\1\0\0",
        /* 'u' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\0\0\0\1\0\1\0\0\0\1\0\1\0\0\1\1\0\0\1\1\0\1\0",
        /* 'v' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\0\0\0\1\0\1\0\0\0\1\0\0\1\0\1\0\0\0\0\1\0\0\0",
        /* 'w' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\0\0\0\1\0\1\0\0\0\1\0\1\0\1\0\1\0\0\1\0\1\0\0",
        /* 'x' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\0\0\0\1\0\0\1\0\1\0\0\0\0\1\0\0\0\0\1\0\1\0\0\1\0\0\0\1\0",
        /* 'y' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\0\0\0\1\0\0\1\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\0",
        /* 'z' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\1\1\0\0\0\0\0\1\0\0\0\1\1\0\0\0\1\0\0\0\0\0\1\1\1\1\0\0",
        /* '{' */ "\0\0\1\1\0\0\1\0\0\0\0\1\0\0\0\1\0\0\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\0\0\0\1\1\0",
        /* '|' */ "\0\1\0\0\1\0\0\1\0\0\1\0\0\1\0\0\1\0\0\1\0\0\1\0",
        /* '}' */ "\1\1\0\0\0\0\0\1\0\0\0\0\1\0\0\0\0\0\1\0\0\0\1\0\0\0\0\1\0\0\0\0\1\0\0\1\1\0\0\0",
        /* '~' */ "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\0\0\1\1\0\0\1\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
    } //
};
