#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "../libs/sortview.h"
#include "../libs/player.h"
#include <stdlib.h>

static SortView sview;

void insert_vector_sort(std::vector<int> &vetor){
    int i,j, remover;
    for(j = 1; j < vetor.size(); j++){
        sview.show(vetor, {i, j}, "gb");//code for libs
        remover = vetor[j];
        i = j - 1;
        while(i >= 0 && vetor[i] > remover){
            sview.show(vetor, {i, j}, "yg");//code for libs
            sview.set_faixa(i,j);//code for libs
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }
        vetor[i + 1] = remover;
    }
}

//void bucket_sort(){

//}

void quick_sort(std::vector<int> &vet, int inicio, int fim){
    if(inicio >= fim){
        return;
    }
    int i, j, pivo;
    i = inicio;
    j = fim;
    pivo = vet[((fim + inicio)/2)];

    sview.show(vet, {i, j, pivo}, "rbc");//code for libs

    while(i < j){
        sview.set_faixa(i,j);//code for libs
        sview.show(vet, {i, j, pivo}, "rbc");//code for libs
        while(vet[i] < pivo){
            i++;
        }
        while(vet[j] > pivo){
            j--;
        }
        if(i <= j){
            sview.show(vet, {i, j, pivo}, "ygc");//code for libs
            std::swap(vet[i], vet[j]);
            sview.show(vet, {i, j,pivo}, "gyc");//code for libs
            i++;
            j--;
        }
        sview.show(vet, {i, j, pivo}, "rbc");//code for libs
    }

    if(j > inicio){
        quick_sort(vet, inicio, j);
    }
    if(i < fim){
        quick_sort(vet, i, fim);
    }
}

void intercala(std::vector<int> &vet, int inicio, int meio, int fim){
    std::list<int> left(vet.begin() + inicio, vet.begin() + meio);
    std::list<int> right(vet.begin() + meio, vet.begin() + fim);

    int i = inicio;

    while (!left.empty() && !right.empty()) {
        if(left.front() < right.front()){
            vet[i] = left.front();
            left.pop_front();
        }else {
            vet[i] = right.front();
            right.pop_front();
        }
        i++;
    }
    while (!left.empty()){
        vet[i] = left.front();
        left.pop_front();
        i++;
    }
    while(!right.empty()) {
        vet[i] = right.front();
        right.pop_front();
        i++;
    }
}

void merge_sort(std::vector<int> &vet, int inicio, int fim){
    if (inicio + 1 == fim){
        return;
    }

    int meio;
    meio = (inicio + fim)/2;

    sview.show(vet, {inicio, meio, fim}, "rgb");//code for libs
    sview.set_faixa(inicio,fim);//code for libs

    //chamada da recursao
    merge_sort(vet, inicio, meio);
    merge_sort(vet, meio, fim);

    sview.show(vet, {inicio, meio, fim}, "cyr");//code for libs
    intercala(vet,inicio,meio,fim);
    sview.show(vet, {inicio, meio, fim}, "rgb");//code for libs
}

void bubble_revese_sort(std::vector<int> &vet){
    int tam = vet.size();
    int cont = 0;
    while(cont < tam){
        for(int i = tam; i > cont; i--){
            sview.show(vet, {i, (i+1)}, "gb");//code for libs
            if(vet[i] < vet[(i-1)]){
                sview.show(vet, {i, (i-1)}, "rb");//code for libs
                std::swap(vet[i], vet[(i-1)]);
                sview.show(vet, {i, (i-1)}, "cb");//code for libs
            }
        }
        cont++;
    }
}

void bubble_sort(std::vector<int> &vet){
    int tam = vet.size();
    while(tam > 1){
        for(int i = 0; i < (tam - 1); i++){
            sview.show(vet, {i, (i+1)}, "gb");//code for libs
            if(vet[i] > vet[(i+1)]){
                sview.show(vet, {i, (i+1)}, "rb");//code for libs
                std::swap(vet[i], vet[(i+1)]);
                sview.show(vet, {i, (i+1)}, "cb");//code for libs
            }
        }
        tam--;
    }
}

void select_reverse_sort(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = tam - 1; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            sview.show(vet, {i, j}, "gb");//code for libs
            if(vet[i] < vet[j]){
                sview.show(vet, {i, j}, "rb");//code for libs
                std::swap(vet[i], vet[j]);
                sview.show(vet, {i, j}, "cb");//code for libs
            }
        }
    }
}

void select_sort(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = 0; i < tam - 1; i++){
        for(int j = i + 1; j < tam; j++){
            sview.show(vet, {i, j}, "gb");//code for libs
            if(vet[j] < vet[i]){
                sview.show(vet, {i, j}, "rb");//code for libs
                std::swap(vet[i], vet[j]);
                sview.show(vet, {i, j}, "cb");//code for libs
            }
        }
    }
}

std::vector<int> init_vet(int qtd, int min, int max){
    std::vector<int> vet;
    vet.reserve(qtd);
    for(int i = 0; i < qtd; i++){
        vet.push_back(rand() % (max - min + 1) + min);
    }
    return vet;
}

int main_sorts(){
    srand(time(NULL));
    my_player->autoplay = true;//code for libs
    sview.set_bar_view();//code for libs
    sview.set_thickness(8);//code for libs

    std::vector<int> vet = init_vet(70, 50, 300);

    //   select_sort(vet);
    //    select_reverse_sort(vet);

    //    bubble_sort(vet);
    //    bubble_revese_sort(vet);

    //     merge_sort(vet, 0, vet.size());

    quick_sort(vet,0,(vet.size() - 1));

    //    insert_vector_sort(vet);

    my_player->wait();//code for lib
    return 0;
}

int main(){
    main_sorts();
}

