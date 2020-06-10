#include <stdlib.h>

#define arrlen(A_)  (sizeof(A_) / sizeof(A_[0]))

#define randint(MAX_) (rand() % MAX_)

#define watch_i(V_)   do { printf(#V_ " = %d\n", (V_)); }while(0)
#define watch_c(V_)   do { printf(#V_ " = %c\n", (V_)); }while(0)
#define watch_3i(X_, Y_, Z_)   do { printf(#X_ " = %d, " #Y_ " = %d, " #Z_ " = %d\n", (X_), (Y_), (Z_)); }while(0)



typedef struct { 
	size_t size; 
	char   str[];
} string;

#ifndef STRING_CREATE_SIZE
#define STRING_CREATE_SIZE   16
#endif

string *string_create_n(size_t size);
string *string_create();
string *string_reserve(string *s, size_t size);
string *string_insert(string *s, int i, int c);
string *string_cat_cstr(string *s1, int i, const char *s2);


int readline(string **out_s, int term);


