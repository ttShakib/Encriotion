#include <stdio.h>
#include <string.h>
#include <math.h>

void primeNum(int lenth, int arra[]) {
  int i = 0, i1, j, k, root; 
  char chack0or1[lenth];
  root = sqrt(lenth);

  if(lenth < 3) { 
  chack0or1[0] = '0'; chack0or1[1] = '1';
 }
  else if (lenth > 2) {
    chack0or1[0] = '0'; chack0or1[1] = '1'; chack0or1[2] = '\0'; 

    for (j = 2, k = 3; j < lenth; j = j + 2, k = k + 2) {
    chack0or1[j] = '1';
    chack0or1[k] = '0'; 
  } 
  chack0or1[j] = '\0'; 

    for (i = 3; i <= root; i = i + 2)
    {
      for (i1 = i+2, k = 2; i1 <= lenth; i1 = i1 + 2, k = k + 2)
      {
        if(i1 % i == 0) {
          chack0or1[i1-1] = '0';
        }

      } 
    } 
   }
   for(i = 0, j = 0; i < lenth; i++) {
    if(chack0or1[i] == '1') {
      arra[j] = i+1; 
      j++;
    }
   } 
   arra[j] = '\0'; 
}

int security() {
    char password[20] = "11", tempass[20];
    printf("Password: ");
    scanf("%s", tempass);

    return strcmp(password, tempass);
}

int main() { 
    char enORd;
    char stringMain[1000], stringEn1[1000], stringEn2[1000], stringEn3[1000], stringEn4[1000];
    int i, j, k, lenth, prelenth, temp; 

    if(0 != security()) {  
    printf("Try again!\n"); 
      printf("incurract password.\n");
      return 1;
    }
      printf("what's you want? Encript(1) Decrypt(0): ");
      scanf(" %c", &enORd);

      if (enORd != '0' && enORd != '1')
      {
        printf("try again. Encript(1) Decrypt(0)\n");

        return 0; 
      } 

     if('1' == enORd) { 
      printf("Encript your Pragraph: ");
      // gets(stringMain);
      // gets(stringMain);
      fgets(stringMain, sizeof(stringMain), stdin);
      fgets(stringMain, sizeof(stringMain), stdin); 
      lenth = strlen(stringMain);
      int  primearra[lenth];

      // 123456789 ({[!@#/%]})
          for(i = 0; i < lenth; i++) { 

                stringEn1[i] = 'd';
              if(stringMain[i] == 'd') {
                stringEn1[i] = 'f';
              }
              else if(stringMain[i] == 'f') {
              }
              else if(stringMain[i] == 'l') {
                stringEn1[i] = 'm';
              }
              else if(stringMain[i] == 'm') {
                stringEn1[i] = 'l';
              } 
              else if(stringMain[i] == ' ') {
                stringEn1[i] = ')';
              }
              else if(stringMain[i] == ')') {
                stringEn1[i] = ' ';
              }
              else {
              stringEn1[i] = stringMain[i];
              } 
            }
            stringEn1[i] = '\0';
 
        for(i = 0; i < lenth; i++) { 
            if((stringEn1[i] >= 65 && stringEn1[i] <= 90)) {
              temp = stringEn1[i];
              stringEn2[i] = temp + 34;
            }
            else if((stringEn1[i] >= 97 && stringEn1[i] <= 122)) {
              temp = stringEn1[i];
              stringEn2[i] = temp - 34;
            }
            else if(stringEn1[i] == 63 || stringEn1[i] == 64) {
              temp = stringEn1[i];
              stringEn2[i] = temp + 26;
            } 
            else if(stringEn1[i] == 123 || stringEn1[i] == 124) {
              temp = stringEn1[i];
              stringEn2[i] = temp - 26;
            } 
            else if((stringEn1[i] >= 34 && stringEn1[i] <= 44)) {
              temp = stringEn1[i];
              stringEn2[i] = temp + 18;
            }
            else if(stringEn1[i] >= 52 && stringEn1[i] <= 62) {
              temp = stringEn1[i];
              stringEn2[i] = temp - 18;
            } 
            else {
              stringEn2[i] = stringEn1[i];
            }
        }
        stringEn2[i] = '\0';
  
        primeNum(lenth, primearra); 
        
        i = 0; j = 0; k = 0;
        for(i = 0; stringEn2[i] != '\0'; i++) {
          if(i == primearra[j]) {
            if((primearra[j] + 1) % 3 == 0) {
              stringEn3[k] = 'E';
              k++; j++; i--;
            }
            else {
            stringEn3[k] = '!';
            k++; j++; i--;
            }
          }
          else {
            stringEn3[k] = stringEn2[i];
            k++;
          }
        }

        stringEn3[k] = '\0';
        temp = 65; k = 0;
        for(i = 0, j = 0; stringEn3[i] != '\0'; i++, j++) {
          if(j == 6) {
            stringEn4[k] = temp;
            i--; j = 0; k++; temp++;
            if(122 < temp) {
              temp = 65;
            }
          }
          else {
            stringEn4[k] = stringEn3[i];
            k++; 
          }
        }
        stringEn4[k] = '\0'; 

      }

      else if('0' == enORd) {
      printf("DeEncrypt your Pragraph: ");
      gets(stringMain);
      gets(stringMain); 
      // fgets(stringMain, 2000, stdin); 

        // 12E3!"A#E$%!B&'S:ECa[!!ZD5/E7]E!};
        for(i = 0, j = 0, k = 0; stringMain[i] != '\0'; i++, j++) {
          if(j == 6) { 
            j = 0; 
          }
          else {
            stringEn1[k] = stringMain[i];
            k++; 
          }
        }
        stringEn1[k] = '\0'; 

        prelenth = k - 1; 
        int  primearra[prelenth];
        primeNum(prelenth, primearra);
        i = 0; j = 0; k = 0;
        for(i = 0; stringEn1[i] != '\0'; i++) {
          if(i == (primearra[j] + j)) { 
            j++;
          }
          else {
            stringEn2[k] = stringEn1[i];
            k++;
          }
        }
        stringEn2[k] ='\0'; 

        for(i = 0; stringEn2[i] != '\0'; i++) {
            if(stringEn2[i] >= 99 && stringEn2[i] <= 124) {
              temp = stringEn2[i];
              stringEn3[i] = temp - 34;
            }
            else if(stringEn2[i] >= 63 && stringEn2[i] <= 88) {
              temp = stringEn2[i];
              stringEn3[i] = temp + 34;
            }
            else if(stringEn2[i] == 89 || stringEn2[i] == 90) {
              temp = stringEn2[i];
              stringEn3[i] = temp - 26;
            } 
            else if(stringEn2[i] == 97 || stringEn2[i] == 98) {
              temp = stringEn2[i];
              stringEn3[i] = temp + 26;
            } 
            else if(stringEn2[i] >= 34 && stringEn2[i] <= 44) {
              temp = stringEn2[i];
              stringEn3[i] = temp + 18;
            }
            else if(stringEn2[i] >= 52 && stringEn2[i] <= 62) {
              temp = stringEn2[i];
              stringEn3[i] = temp - 18;
            } 
            else {
              stringEn3[i] = stringEn2[i];
            }
        }
          stringEn3[i] = '\0';

        for(i = 0; stringEn3[i] != '\0'; i++) { 

              if(stringEn3[i] == 'd') {
                stringEn4[i] = 'f';
              }
              else if(stringEn3[i] == 'f') {
                stringEn4[i] = 'd';
              }
              else if(stringEn3[i] == 'l') {
                stringEn4[i] = 'm';
              }
              else if(stringEn3[i] == 'm') {
                stringEn4[i] = 'l';
              } 
              else if(stringEn3[i] == ' ') {
                stringEn4[i] = ')';
              }
              else if(stringEn3[i] == ')') {
                stringEn4[i] = ' ';
              }
              else {
                stringEn4[i] = stringEn3[i];
              }
            }
            stringEn4[i] = '\0';
        }
        printf("Output: ");
        printf("%s\n", stringEn4); 

    return 0;
}