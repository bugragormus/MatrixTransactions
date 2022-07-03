#include <stdio.h>
#include <string.h>

int main () {

    int secimsoru, sbt, toplam=0;
    int matrisBir[20][20], matrisIki[20][20], matrisSonuc[20][20], matrisCarp[20][20], sbtCarp1[20][20], sbtCarp2[20][20];
    int i, j;
    char devam;
    long determinant1, determinant2;
    float determinanta=0;
    float determinantb=0;
    int flag=1;

    printf("\nHOŞGELDİNİZ!\n\n");
    printf("3X3 Birinci Matrisi Giriniz\n\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("[%d][%d]= ", i+1, j+1);
            scanf("%d", &matrisBir[i][j]);
        }
    }
    printf("\n3X3 İkinci Matrisi Giriniz\n\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("[%d][%d]= ", i+1, j+1);
            scanf("%d", &matrisIki[i][j]);
        }
    }
    
soru:
    printf("\n");
    printf("İşlem Listesi:");
    printf("\n\n1. Matrisleri Toplamak İçin ---> 1\n\n2. Matrislerin Farkını Almak İçin ---> 2\n\n3. Matrisleri Çarpmak İçin ---> 3\n\n4. Matrisleri Sabit Bir Sayıyla Çarpmak İçin ---> 4\n\n5. Matrislerin Determinantını Hesaplamak İçin ---> 5\n\n6. Matrislerin Tersini Hesaplamak İçin ---> 6\n\n7. Matrislerin İnvolutif Olup Olmadığını Kontrol Etmek İçin ---> 7\n\n");
    printf("Yapmak İstediğiniz İşlemin Kodunu Giriniz: ");
    scanf("%d", &secimsoru);

    if (secimsoru==1) {
        printf("\nMatrislerin Toplamı: \n\n");
        for (i=0; i<3; i++) {
            for (j=0; j<3; j++) {
                matrisSonuc[i][j] = matrisBir[i][j] + matrisIki[i][j];
                printf("%d\t", matrisSonuc[i][j]);
            }
            printf("\n");
        }
    }

    else if (secimsoru==2) {
        printf("\nMatrislerin Farkı: \n\n");
        for (i=0; i<3; i++) {
            for (j=0; j<3; j++) {
                matrisSonuc[i][j] = matrisBir[i][j] - matrisIki[i][j];
                printf("%d\t", matrisSonuc[i][j]);
            }
            printf("\n");
        }
    }

    else if (secimsoru==3) {
        printf("\nMatrislerin Çarpımı: \n\n");
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                for(int k=0; k<3; k++) {
                    toplam += matrisBir[i][k] * matrisIki[k][j];
                }
                matrisCarp[i][j] = toplam;
                toplam = 0;
                printf("%d\t", matrisCarp[i][j]);
            }
            printf("\n");
        }
    }

    else if (secimsoru==4) {
        printf("Çarpmak İstediğiniz Sabit Değeri Giriniz: ");
        scanf("%d", &sbt);
        printf("\nBirinci Matrisin Sabitle Çarpımı: \n\n");
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                sbtCarp1[j][j] = matrisBir[i][j] * sbt;
                printf("%d\t", sbtCarp1[j][j]);
            }
            printf("\n");
        }
        printf("\n");
        printf("\nİkinci Matrisin Sabitle Çarpımı: \n\n");
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                sbtCarp2[j][j] = matrisIki[i][j] * sbt;
                printf("%d\t", sbtCarp2[j][j]);
            }
            printf("\n");
        }
    }

    else if (secimsoru==5) {
        printf("\nBirinci Matrisin Determinantı: \n\n");
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                determinant1 = matrisBir[0][0] * ((matrisBir[1][1]*matrisBir[2][2]) - (matrisBir[2][1]*matrisBir[1][2])) -matrisBir[0][1] * (matrisBir[1][0]
                               * matrisBir[2][2] - matrisBir[2][0] * matrisBir[1][2]) + matrisBir[0][2] * (matrisBir[1][0] * matrisBir[2][1] - matrisBir[2][0] * matrisBir[1][1]);
                printf("%ld\t", determinant1);
            }
            printf("\n");
        }
        printf("\nİkinci Matrisin Determinantı: \n\n");
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                determinant2 = matrisIki[0][0] * ((matrisIki[1][1]*matrisIki[2][2]) - (matrisIki[2][1]*matrisIki[1][2])) -matrisIki[0][1] * (matrisIki[1][0]
                               * matrisIki[2][2] - matrisIki[2][0] * matrisIki[1][2]) + matrisIki[0][2] * (matrisIki[1][0] * matrisIki[2][1] - matrisIki[2][0] * matrisIki[1][1]);
                printf("%ld\t", determinant2);
            }
            printf("\n");
        }
    }

    else if (secimsoru==6) {
        printf("\nBirinci Matrisin Tersi: \n\n");
        for(i=0; i<3; i++)
            determinanta = determinanta + (matrisBir[0][i]*(matrisBir[1][(i+1)%3]*matrisBir[2][(i+2)%3] - matrisBir[1][(i+2)%3]*matrisBir[2][(i+1)%3]));


        for(i=0; i<3; i++) {
            for(j=0; j<3; j++)
                printf("%.5f\t",((matrisBir[(i+1)%3][(j+1)%3] * matrisBir[(i+2)%3][(j+2)%3]) - (matrisBir[(i+1)%3][(j+2)%3]*matrisBir[(i+2)%3][(j+1)%3]))/ determinanta);
            printf("\n");
        }
        printf("\nİkinci Matrisin Tersi: \n\n");
        for(i=0; i<3; i++)
            determinantb = determinantb + (matrisIki[0][i]*(matrisIki[1][(i+1)%3]*matrisIki[2][(i+2)%3] - matrisIki[1][(i+2)%3]*matrisIki[2][(i+1)%3]));


        for(i=0; i<3; i++) {
            for(j=0; j<3; j++)
                printf("%.5f\t",((matrisIki[(i+1)%3][(j+1)%3] * matrisIki[(i+2)%3][(j+2)%3]) - (matrisIki[(i+1)%3][(j+2)%3]*matrisIki[(i+2)%3][(j+1)%3]))/ determinantb);
            printf("\n");
        }
    }

    else if (secimsoru==7 ) {
        printf("\nBirinci Matris: \n\n");
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                for(int k=0; k<3; k++) {
                    toplam += matrisBir[i][k] * matrisBir[k][j];
                }
                matrisCarp[i][j] = toplam;
                toplam = 0;
            }
        }
        for (i=0; i<3; i++) {
            for (j=0; j<3; j++) {
            }
        }
        for (i=0; i<3; i++) {
            for (j=0; j<3; j++) {
                if((matrisCarp[i][i] %1 != 0 ) || (( i != j) && (matrisCarp[i][j] != 0))) {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1 )
            printf("İNVOLUTİFTİR.\n");
        else
            printf("İnvolutif DEĞİLDİR!\n");


        printf("\nİkinci Matris: \n\n");
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                for(int k=0; k<3; k++) {
                    toplam += matrisIki[i][k] * matrisIki[k][j];
                }
                matrisCarp[i][j] = toplam;
                toplam = 0;
            }
        }
        for (i=0; i<3; i++) {
            for (j=0; j<3; j++) {
                if((matrisCarp[i][i] %1 != 0 ) || (( i != j) && (matrisCarp[i][j] != 0))) {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1 )

            printf("İNVOLUTİFTİR.\n");
        else
            printf("İnvolutif DEĞİLDİR!\n");
    }

    else {
        printf("\nGeçersiz İşlem Kodu Girdiniz!");
    }

gecersiz:
    printf("\n\nBaşka İşlem Yapmak İster Misiniz?\n");
    printf("Evet İçin ---> E/e\nHayır İçin ---> H/h\n");
    scanf("%s", &devam);
    if(devam=='e' || devam=='E') {
        goto soru;
    }
    else if(devam=='h' || devam=='H') {
        return 0;
    }
    else {
        printf("Geçersiz Bir Karakter Girdiniz.");
        goto gecersiz;
    }
    return 0;
}


