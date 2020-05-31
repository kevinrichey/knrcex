
#define arrlen(A_)  (sizeof(A_) / sizeof(A_[0]))

#define randint(MAX_) (rand() % MAX_)

#define watch_i(V_)   do { printf(#V_ " = %d\n", (V_)); }while(0)
#define watch_3i(X_, Y_, Z_)   do { printf(#X_ " = %d, " #Y_ " = %d, " #Z_ " = %d\n", (X_), (Y_), (Z_)); }while(0)
