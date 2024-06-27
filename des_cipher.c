    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>

    int parity_check(char* key) {
        int ones = 0;
        int eval = 0;
        int ctr = 0;
    
        for (int i = 0; i < strlen(key); i++){
        if (key[i] == '1'){
            ones++;   
        }
        else if (ctr == 7) {
            eval = ones % 2;
            if (eval == 0) {
                return 1;
            }
            ctr = 0;
            ones = 0;
        }
        ctr++;
        }
        return 0;
    }

    void dec_to_bin (int num, char* new_num, int length) {
        int i = 0;
        int ctr = 0;
        int i_start = 0;
        char *dup_num = (char*) malloc(200 * sizeof(dup_num));

        while (num != 0){
            if (num % 2 == 1) {
                dup_num[i] = '1';
            } 
            else {
                dup_num[i] = '0';
            }
            num = num/2;
            i = i + 1;
            ctr += 1;
        }

        for (int i = 0; i < 8; i++){
            if (i < 8 - ctr){
              new_num[i] = '0';
            }
            else {
              if (ctr - i_start - 1 < 0){
                i_start++;
              }
              else {
              new_num[i] = dup_num[ctr - i_start - 1];
              i_start++;
              }
            }          
        }
        new_num[8] = '\0';
    }

    int bin_to_dec (char* string) {
        int total = 0;

        for (int i = 0; i < 21; i++) {
            if (string[i] == '1') {
                total += pow(2,27 - i);
            }
        }
        return total;
    }

    int bin_to_hex (char *string){
        if (strcmp(string, "0000") == 0 || strcmp(string, "00") == 0){return 0;}
        if (strcmp(string, "0001") == 0 || strcmp(string, "01") == 0){return 1;}
        if (strcmp(string, "0010") == 0 || strcmp(string, "10") == 0){return 2;}
        if (strcmp(string, "0011") == 0 || strcmp(string, "11") == 0) {return 3;}
        if (strcmp(string, "0100") == 0) {return 4;}
        if (strcmp(string, "0101") == 0) {return 5;}
        if (strcmp(string, "0110") == 0) {return 6;}
        if (strcmp(string, "0111") == 0) {return 7;}
        if (strcmp(string, "1000") == 0){return 8;}
        if (strcmp(string, "1001") == 0){return 9;}
        if (strcmp(string, "1010") == 0){return 10;}
        if (strcmp(string, "1011") == 0){return 11;}
        if (strcmp(string, "1100") == 0){return 12;}
        if (strcmp(string, "1101") == 0){return 13;}
        if (strcmp(string, "1110") == 0){return 14;}
        if (strcmp(string, "1111") == 0){return 15;}
    }

    const char * int_hex_to_bin (int num) {
        if (num == 0) {return "0000";}
        if (num == 1) {return "0001";}
        if (num == 2) {return "0010";}
        if (num == 3) {return "0011";}
        if (num == 4) {return "0100";}
        if (num == 5) {return "0101";}
        if (num == 6) {return "0110";}
        if (num == 7) {return "0111";}
        if (num == 8) {return "1000";}
        if (num == 9) {return "1001";}
        if (num == 10) {return "1010";}
        if (num == 11) {return "1011";}
        if (num == 12) {return "1100";}
        if (num == 13) {return "1101";}
        if (num == 14) {return "1110";}
        if (num == 15) {return "1111";}
    }


    void *parity_drop(char *key) {
        char *modkey;
        modkey = (char*) malloc(56 * sizeof(char));

        int pbd_table[56] = {57, 49, 41, 33, 25, 17, 9, 1,
                            58, 50, 42, 34, 26, 18, 10, 2,
                            59, 51, 43, 35, 27, 19, 11, 3,
                            60, 52, 44, 36, 63, 55, 47, 39,
                            31, 23, 15, 7, 62, 54, 46, 38,
                            30, 22, 14, 6, 61, 53, 45, 37,
                            29, 21, 13, 5, 28, 20, 12, 4};

        for (int i = 0; i < 56; i++) {
            modkey[i] = key[pbd_table[i]-1];
        }

        for (int j = 0; j < 56; j++) {
            key[j] = modkey[j];
        }
        key[56] = '\0';
    }


    void initial_permu(char *text) {
        char *modtext;
        modtext = (char*) malloc(64 * sizeof(char));

        int ip_table[64] = {58, 50, 42, 34, 26, 18, 10, 2,
                            60, 52, 44, 36, 28, 20, 12, 4,
                            62, 54, 46, 38, 30, 22, 14, 6,
                            64, 56, 48, 40, 32, 24, 16, 8,
                            57, 49, 41, 33, 25, 17, 9, 1,
                            59, 51, 43, 35, 27, 19, 11, 3,
                            61, 53, 45, 37, 29, 21, 13, 5,
                            63, 55, 47, 39, 31, 23, 15, 7};

        for (int i = 0; i < 64; i++) {
            modtext[i] = text[ip_table[i]-1];
        }

        for (int j = 0; j < 64; j++) {
            text[j] = modtext[j];
        }
        text[64] = '\0';
    }

    void split(char *text, char *left_string, char *right_string){
        int ctr = 0;
        for (int i = 0; i < strlen(text); i++){
            if (i < strlen(text)/2) {
                left_string[i] = text[i];
            }
            else {
                right_string[ctr] = text[i];
                ctr += 1;
            }
        }
        left_string[strlen(text)/2] = '\0';
        right_string[ctr] = '\0';    
    }

    void expansion(char *right_text){
        char *modtext;
        modtext = (char*) malloc(48 * sizeof(char));

        int expd_table[48] = {  32, 1, 2, 3, 4, 5,
                                4, 5, 6, 7, 8, 9,
                                8, 9, 10, 11, 12, 13,
                                12, 13, 14, 15, 16, 17,
                                16, 17, 18, 19, 20, 21,
                                20, 21, 22, 23, 24, 25,
                                24, 25, 26, 27, 28, 29,
                                28, 29, 30, 31, 32, 1 };  

        for (int i = 0; i < 48; i++) {
            modtext[i] = right_text[expd_table[i]-1];
        }

        for (int j = 0; j < 48; j++) {
            right_text[j] = modtext[j];
        }
        right_text[48] = '\0';    
    }

    void whitener(char *right_string, char newkey[], char *wright_string){
        for (int i = 0; i < 48; i++) {
            if (right_string[i] == newkey[i]) {
                wright_string[i] = '0';
            }
            else {
                wright_string[i] = '1';
            }
        }
        wright_string[48] = '\0';
    }

    void xor(char *left_string, char *sbox_string, char *fin_string ){
        for (int i = 0; i < 32; i++) {
            if (left_string[i] == sbox_string[i]) {
                fin_string[i] = '0';
            }
            else {
                fin_string[i] = '1';
            }
        }
        fin_string[32] = '\0';
    }

    void sbox(char *sbox_string, char *wright_string){
        sbox_string[0] = '\0';

        int sbox1[4][16] = {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
                        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
                        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
                        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11 ,3 ,14, 10, 0, 6, 13}};

        int sbox2[4][16] = {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
                            {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
                            {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
                            {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}};
        
        int sbox3[4][16] = {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
                            {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
                            {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
                            {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}};
        
        int sbox4[4][16] = {{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
                        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
                        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
                        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}};

        int sbox5[4][16] = {{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
                        {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
                        {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
                        {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}};
        
        int sbox6[4][16] = {{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
                            {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
                            {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
                            {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}};

        int sbox7[4][16] = {{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
                            {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
                            {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
                            {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}};
        
        int sbox8[4][16] = {{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
                            {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
                            {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
                            {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}};

        int num_arr[9];
        char *row;
        char *col;
        int int_row, int_col, num;

        row = malloc( sizeof(*row) * ( 2 ) );
        col = malloc( sizeof(*col) * ( 4 ) );

        for (int i = 0; i < 6; i++){
            if (i == 0) {
                row[0] = wright_string[0];
            }
            else if (i == 5) {
                row[1] = wright_string[5];
            }
            else if (i != 0 || i != 5) {
                col[i-1] = wright_string[i];
            }
        }

        row[2] = '\0';
        col[4] = '\0';
        

        int_row = bin_to_hex(row);
        int_col = bin_to_hex(col);

        num_arr[0] = sbox1[int_row][int_col];
        


        for (int i = 6; i < 12; i++){
            if (i == 6) {
                row[0] = wright_string[6];
            }
            else if (i == 11) {
                row[1] = wright_string[11];
            }
            else if (i != 6 || i != 11) {
                col[i-7] = wright_string[i];
            }
        }

        row[2] = '\0';
        col[4] = '\0';
        

        int_row = bin_to_hex(row);
        int_col = bin_to_hex(col);

        num_arr[1] = sbox2[int_row][int_col];


        for (int i = 12; i < 18; i++){
            if (i == 12) {
                row[0] = wright_string[12];
            }
            else if (i == 17) {
                row[1] = wright_string[17];
            }
            else if (i != 12 || i != 17) {
                col[i-13] = wright_string[i];
            }
        }

        row[2] = '\0';
        col[4] = '\0';
        

        int_row = bin_to_hex(row);
        int_col = bin_to_hex(col);


        num_arr[2] = sbox3[int_row][int_col];



        for (int i = 18; i < 24; i++){
            if (i == 18) {
                row[0] = wright_string[18];
            }
            else if (i == 23) {
                row[1] = wright_string[23];
            }
            else if (i != 18 || i != 23) {
                col[i-19] = wright_string[i];
            }
        }

        row[2] = '\0';
        col[4] = '\0';
        

        int_row = bin_to_hex(row);
        int_col = bin_to_hex(col);

        num_arr[3] = sbox4[int_row][int_col];


        for (int i = 24; i < 30; i++){
            if (i == 24) {
                row[0] = wright_string[24];
            }
            else if (i == 29) {
                row[1] = wright_string[29];
            }
            else if (i != 24 || i != 29) {
                col[i-25] = wright_string[i];
            }
        }

        row[2] = '\0';
        col[4] = '\0';
        

        int_row = bin_to_hex(row);
        int_col = bin_to_hex(col);

        num_arr[4] = sbox5[int_row][int_col];

        for (int i = 30; i < 36; i++){
            if (i == 30) {
                row[0] = wright_string[30];
            }
            else if (i == 35) {
                row[1] = wright_string[35];
            }
            else if (i != 30 || i != 35) {
                col[i-31] = wright_string[i];
            }
        }

        row[2] = '\0';
        col[4] = '\0';
        

        int_row = bin_to_hex(row);
        int_col = bin_to_hex(col);

        num_arr[5] = sbox6[int_row][int_col];


        for (int i = 36; i < 42; i++){
            if (i == 36) {
                row[0] = wright_string[36];
            }
            else if (i == 41) {
                row[1] = wright_string[41];
            }
            else if (i != 36 || i != 41) {
                col[i-37] = wright_string[i];
            }
        }

        row[2] = '\0';
        col[4] = '\0';
        

        int_row = bin_to_hex(row);
        int_col = bin_to_hex(col);

        num_arr[6] = sbox7[int_row][int_col];


        for (int i = 42; i < 48; i++){
            if (i == 42) {
                row[0] = wright_string[42];
            }
            else if (i == 47) {
                row[1] = wright_string[47];
            }
            else if (i != 42 || i != 47) {
                col[i-43] = wright_string[i];
            }
        }

        row[2] = '\0';
        col[4] = '\0';
        

        int_row = bin_to_hex(row);
        int_col = bin_to_hex(col);

        num_arr[7] = sbox8[int_row][int_col];

        for (int j = 0; j < 8; j++){
            strcat(sbox_string, int_hex_to_bin(num_arr[j]));
        }
    }

    void straight_permu(char *string){
        char *modtext;
        modtext = (char*) malloc(32 * sizeof(char));

        int sp_table[32] = {16, 7, 20, 21, 29, 12, 28, 17,
                            1, 15, 23, 26, 5, 18, 31, 10,
                            2, 8, 24, 14, 32, 27, 3, 9,
                            19, 13, 30, 6, 22, 11, 4, 25};

        for (int i = 0; i < 32; i++) {
            modtext[i] = string[sp_table[i]-1];
        }

        for (int j = 0; j < 32; j++) {
            string[j] = modtext[j];
        }
        string[32] = '\0';    
    }

    void swapper_left(char *new_left, char *right_string){
        for (int i = 0; i < 32; i++){
            new_left[i] = right_string[i];
        }
        new_left[32] = '\0';
    }

    void swapper_right(char *new_right, char *fin_string){
        for (int j = 0; j < 32; j++){
            new_right[j] = fin_string[j];
        }
        new_right[32] = '\0';
    }


    void *split_and_shift(char *key, char *sleft_key, char *sright_key, int round) {
        char *left_key;
        char *right_key;
        int lmsb1, lmsb2, rmsb1, rmsb2;
        int bit_shift_table[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
        int num_bits = bit_shift_table[round];

        left_key= malloc( sizeof(*left_key) * ( 100 ) );
        right_key= malloc( sizeof(*right_key) * ( 100 ) );

        for (int j = 0; j < 56; j++) {
            if (j < 28) {
                left_key[j] = key[j];
            }
            else {
                right_key[j-28] = key[j];
            }
        }

        left_key[28] = '\0';
        right_key[28] = '\0';

        lmsb1 = left_key[0];
        lmsb2 = left_key[1];
        rmsb1 = right_key[0];
        rmsb2 = right_key[1];
        
        for (int j = 0; j < 28-num_bits; j++) {
            sleft_key[j] = left_key[j+num_bits];
            sright_key[j] = right_key[j+num_bits];
        }   

        if (num_bits == 1) {
            sleft_key[27] = lmsb1;
            sright_key[27] = rmsb1;
        }
        else {
            sleft_key[26] = lmsb1;
            sleft_key[27] = lmsb2;
            sright_key[26] = rmsb1;
            sright_key[27] = rmsb2;
        }
        sleft_key[28] = '\0';
        sright_key[28] = '\0';
    }

    char * key_compre(char *newkey ,char *key) {
        char *modkey;
        modkey = (char*) malloc(100 * sizeof(char));

        int keycompre_table[48] = {14, 17, 11, 24, 1, 5, 3, 28,
                            15, 6, 21, 10, 23, 19, 12, 4,
                            26, 8, 16, 7, 27, 20, 13, 2,
                            41, 52, 31, 37, 47, 55, 30, 40,
                            51, 45, 33, 48, 44, 49, 39, 56,
                            34, 53, 46, 42, 50, 36, 29, 32};

        for (int i = 0; i < 48; i++) {
            modkey[i] = key[keycompre_table[i]-1];
        }

        for (int j = 0; j < 56; j++) {
            newkey[j] = modkey[j];
        }
        newkey[48] = '\0';
        return newkey;
    }

    void *final_permu(char *newstring){
        char *modtext;
        modtext = (char*) malloc(64 * sizeof(char));

        int fp_table[64] = {40, 8, 48, 16, 56, 24, 64, 32,
                            39, 7, 47, 15, 55, 23, 63, 31,
                            38, 6, 46, 14, 54, 22, 62, 30,
                            37, 5, 45, 13, 53, 21, 61, 29,
                            36, 4, 44, 12, 52, 20, 60, 28,
                            35, 3, 43, 11, 51, 19, 59, 27,
                            34, 2, 42, 10, 50, 18, 58, 26,
                            33, 1, 41, 9, 49, 17, 57, 25};

        for (int i = 0; i < 64; i++) {
            modtext[i] = newstring[fp_table[i]-1];
        }

        for (int j = 0; j < 64; j++) {
            newstring[j] = modtext[j];
        }
        newstring[64] = '\0';        
    }

    void duplicate_str(char *dup_string, char *string){
        for (int i = 0; i < strlen(string); i++){
            dup_string[i] = string[i];
        }
        dup_string[strlen(string)] = '\0';
    }

    void * mixer_key(char *key, int round){
        char *newkey, *sleft_key, *sright_key;

        //Split, Shift, and Concatenate
        sleft_key = malloc( sizeof(*sleft_key) * ( 200 ) );
        sright_key = malloc( sizeof(*sright_key) * ( 200 ) );
        
        split_and_shift(key, sleft_key, sright_key, round);
        newkey = strcat(sleft_key, sright_key);
        
        for (int i = 0; i < strlen(newkey); i++){
            key[i] = newkey[i];
        }
    }

    char * mixer_text (char *newkey, char *string, int length, int round){
        char *left_string, *right_string;
        char *wright_string;
        char *sbox_string;
        char *fin_string;
        char *dup_right;

        // SPLIT L and R
        left_string = malloc( sizeof(*left_string) * ( 200 ) );
        right_string = malloc( sizeof(*right_string) * ( 200 ) );
        dup_right = malloc( sizeof(*dup_right) * ( 200 ) );
        split(string, left_string, right_string);
        duplicate_str(dup_right, right_string);


        // EXPANSION D-BOX
        expansion(right_string);

        //WHITENER
        wright_string = malloc( sizeof(*wright_string) * ( 200 ) );
        whitener(right_string, newkey, wright_string);

        //S-BOX
        sbox_string = malloc( sizeof(*sbox_string) * ( 200 ) );
        sbox(sbox_string, wright_string);

        //STRAIGHT PERMUTATION
        straight_permu(sbox_string);

        //L XOR f
        fin_string = malloc( sizeof(*fin_string) * ( 200 ) );
        xor(left_string, sbox_string, fin_string);
        
        //CONCATENATE
        if (round != 15) {
            string = strcat(dup_right, fin_string);
        }
        else {
            string = strcat(fin_string, dup_right);
        }
        return string;
    }

    void *dup_str_w_len(char *dup, char *string, int start, int end){
            for (int i = start; i < end; i++){
            dup[i - start] = string[i];
        }
        dup[end - start] = '\0';   
    }

    void *check_len (char *cstring, int length, int idiv){
      int ctr = (idiv*64) - length*8 ;
      for (int j = 0; j <= ctr/8; j++){
          strcat(cstring, "00000000\0");
      }    
        cstring[strlen(cstring)] = '\0';  
    }


    int main() {
        char *key;
        char *string;
        char *newkey, *newstring;
        char *new_num, *cstring;
        char temp;
        int num, length, idiv;
        double div;

        key = malloc( sizeof(*key) * ( 100 ) );
        string = malloc( sizeof(*string) * ( 200 ) );

        newkey = malloc( sizeof(*newkey) * ( 100 ) );
        new_num = malloc( sizeof(*new_num) * ( 100 ) );
        cstring = malloc( sizeof(*cstring) * ( 300 ) );
        newstring = malloc( sizeof(*newstring) * ( 100 ) );
      

        // INPUT

        scanf("%[^\n]", string);
        scanf("%c",&temp);
        scanf("%[^\n]", key);

        string[strlen(string)] = '\0';
        length = strlen(string);
        
        div = ceil((double)(strlen(string)*8)/64);
        idiv = (int)div;

        // Check if key is valid

        if (parity_check(key) == 1) {
            printf("invalid key");
        }
        else {
        //Parity Bit Drop
        parity_drop(key);
    
          //Binary Conversion
          for (int i = 0; i < length; i++){
              num = (int)string[i];
              dec_to_bin(num, new_num, length);
              strcat(cstring, new_num);
          }

        check_len(cstring, length, idiv);


        for (int i = 0; i < idiv; i++) {
            dup_str_w_len(newstring, cstring, (i)*64, (i+1)*64);

            // Initial Permutation
            initial_permu(newstring);
            for (int i = 0; i < 16; i++){
                mixer_key(key, i);
                //Key Compression
                newkey = key_compre(newkey, key);
                newstring = mixer_text(newkey, newstring, length, i);
            }
            final_permu(newstring);
            printf("%s", newstring);
      }
  }
  return 0;
}
    
        