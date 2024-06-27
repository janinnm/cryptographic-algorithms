#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    double p,q,e;
    char action[8];
    double msg;
    double ephi, R, d, n;
    int ctr, num_input;
   
    scanf("%lf %lf", &p, &q);
    scanf("%lf", &e);
    scanf("%d", &num_input);

    ctr = 0;
    while (ctr != num_input) {
      scanf("%s %lf", action, &msg);
      n = p*q;
      ephi = (p-1)*(q-1); //euler phi
      double C = msg; //for encryption
      double m = msg; //for decryption
      // ---------------ENCRYPTION----------------
      if (strcmp(action, "encrypt") == 0) {
        for (int i = 0; i < e - 1 ; i++) {
          C = fmod((C * msg), n);
        }
        C = nearbyintf(C);
        printf("%d\n", C);
      }

      // ---------------DECRYPTION----------------
      else {
        while (fmod((e*d), ephi) != 1) {
          d++;
        }
        for (int i = 0; i < d - 1; i++) {
          m = fmod((m * msg), n);
        }
        d = 0;
        m = nearbyintf(m);
        printf("%d\n", m);
      }
      ctr++;
    }
}