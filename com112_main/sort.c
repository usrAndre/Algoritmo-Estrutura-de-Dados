
void bubblesort(int *, int);
void quicksort(int *, int, int);
int particao(int *, int, int);
void mergesort(int *, int, int, int);
void merge(int *, int, int, int, int);
void insercao_shellsort(int *, int, int, int);
void selecao_direta(int *, int);

void sort(){
    void bubblesort(int *vet, int tam){
        int troca, k, fim, aux;
        int *p, *q;
        troca = 1;
        fim = tam - 1;
        while(troca==1){
            troca = 0;
            p = vet;
            q = vet;
            q++;
            for(k=0; k<fim; k++){
                if(*p > *q){
                    troca = 1;
                    aux = *p;
                    *p = *q;
                    *q = aux;
                }
                p++;
                q++;
            }
            fim--;
        }
    }

    void quicksort(int *vet, int inf, int sup){
        int k;
        if(sup>inf){
            k = particao(vet, inf, sup);
            particao(vet, inf, k-1);
            particao(vet, k+1, sup);
        }
    }


    /**********************************************METODO QUICKSORT - PARTICAO*************************************************/

    int particao(int *vet, int inf, int sup){
        int m, k, aux;
        int *p, *q;
        k = inf;
        p = inf + vet;
        q = sup + vet;
        m = *p;
        do{
            while(sup > inf && *q >= m){
                sup--;
                q = sup + vet;
            }
            k = sup;
            if(sup != inf){
                aux = *p;
                *p = *q;
                *q = aux;
                while(inf < sup && *p <= m){
                    inf++;
                    p++;
                }
                k = inf;
                if(inf != sup){
                    aux = *p;
                    *p = *q;
                    *q = aux;
                }
            }
        }while(inf != sup);
        return k;
    }

    /**********************************************METODO MERGESORT******************************************************/

    void mergesort(int *vet, int l, int r, int tam){
        int meio;
        if(l<r){
            meio = (l+r)/2;
            mergesort(vet, l, meio, tam);
            mergesort(vet, meio+1, r, tam);
            merge(vet, l, meio, r, tam);
        }
    }

    /**********************************************METODO MERGESORT - MERGE***************************************************/

    void merge(int *vet, int l, int meio, int r, int tam){
        int i, j, k;
        int *aux, *p, *q, *t;
        aux = (int*) calloc(tam, sizeof(int));
        i = j = l;
        k = meio + 1;
        while((j<=meio) && (k<=r)){
            p = j + vet;
            q = k + vet;
            t = i + aux;
            if(*p < *q){
                *t = *p;
                j++;
            }
            else{
                *t = *q;
                k++;
            }
            i++;
        }
        while(j<=meio){
            t = i + aux;
            p = j + vet;
            *t = *p;
            i++;
            j++;
        }
        for(i=l; i<k; i++){
            p = i + vet;
            t = i + aux;
            *p = *t;
        }
    }

    /**********************************************METODO SHELLSORT******************************************************/

    void shellsort(int *vet, int tam, int h){
        int i;
        while(h>=1){
            for(i=0; i<=h; i++)
                insercao_shellsort(vet, tam, i, h);
            h = h / 2;
        }
    }

    /**********************************************METODO SHELLSORT - INSERCAO****************************************************/

    void insercao_shellsort(int *vet, int tam, int i, int h){
        int j, k, t, ch;
        int *p, *q;
        for(j=0; j<tam; j++){
            k = 0;
            t = j - 1;
            p = j + vet;
            ch = *p;
            while(t>=0 && k==0){
                p = t + vet;
                if(ch < *p){
                    q = (t+1) + vet;
                    *q = *p;
                    t--;
                }
                else
                    k = t + 1;
            }
            q = k + vet;
            *q = ch;
        }
    }

    void selecao_direta(int *vet, int tam){
        int k, t, aux, troca, min;
        int *p, *q, *r;
        troca = 0;
        for(k=0; k<tam-1; k++){
            p = k + vet;
            min = *p;
            for(t=k+1; t<tam; t++){
                q =  t + vet;
                if(*q < min){
                    min = *q;
                    r = q;
                    troca = 1;
                }
            }
            if(troca==1){
                aux = *p;
                *p = *r;
                *r = aux;
                troca = 0;
            }
        }
    }
}
