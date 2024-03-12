/* arbol de busqueda binaria con menu en c++
*/

// librerias

#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

// nodo raiz del arbol binario

struct Nodo{
    int dato;
    Nodo *derecha;
    Nodo *izquierda;
    Nodo *padre; // creamos nodo padre para que exista referencia de quien es el padre de cada nodo creado
};

// creacion del arbol iniciado en nulo
    Nodo *arbol=NULL;

// prototipo de las funciones, para que se vea bonito

   Nodo *crearNodo(int,Nodo *);//indicamos quien sera el padre del nodo que vamos a crear
   void menu();
   void insertarNodo(Nodo *&,int, Nodo *); // void con parametro, arbol tipo puntero, un entero y quien va a ser en padre del nodo que vamos a ingresar
   void mostrarArbol(Nodo *,int); // void con parametro, arbol tipo puntero y un entero
   bool buscarNodo(Nodo*,int);// void con parametro, arbol tipo puntero y un entero
   void Preorden(Nodo *);// void con parametro, arbol tipo puntero
   void Inorden(Nodo *);// void con parametro, arbol tipo puntero
   void Postorden(Nodo*);// void con parametro, arbol tipo puntero
   void Eliminar(Nodo *,int);
   void EliminarNodo(Nodo *);
   Nodo *minimo(Nodo *);
   void reemplazar(Nodo *,Nodo *);
   void destruirNodo(Nodo *);



// funcion principal main
int main(){
    menu();// invocacion de la funcion menu en el metodo main
    getch();
    return 0;
}

//funcion del menu
void menu(){
int dato, opcion, contador=0;

do{// impresion de pantalla del menu
cout<<"\t-----ARBOL BINARIO DE BUSQUEDA VOL. 1 -----"<<endl;
cout<<"1.- Crear arbol"<<endl;
cout<<"2.- Mostrar arbol"<<endl;
cout<<"3.- Buscar arbol"<<endl;
cout<<"4.- Recorre el arbol en Preorden"<<endl;
cout<<"5.- Recorre el arbol en Inorden"<<endl;
cout<<"6.- Recorre el arbol en Postorden"<<endl;
cout<<"7.- Eliminar un nodo del arbol "<<endl;
cout<<"8.- salir"<<endl;
cout<<"Ingrese un opcion: ";
cin>>opcion;// lectura de la ocpion que ingresa el usuario

switch(opcion){// funciones que ejecuta del swicth segun la opcion del usuario
case 1: cout<<"\n Digite un numero para crear el nodo: ";
        cin>>dato;
        insertarNodo(arbol,dato,NULL); // invocamos la funcion para insertar un nuevo nodo
        cout<<"\n";
        system("pause");
        break;
case 2: cout<<"\t Mostrando arbol completo: \n\n";
        mostrarArbol(arbol, contador);//invocamos la funcion para mostrar arbol
        cout<<"\n      ";
        system("pause");
        break;
case 3: cout<<"\n ingrese el numero que desea buscar: ";
        cin>>dato;
        if(buscarNodo(arbol,dato)== true){//condicional para el funcionamiento del bool
            cout<<"\n elemento encontrado "<<dato<<endl;
        }else{
            cout<<"\n Elemento no encontrado\n";
        }
        cout<<"\n";
        system("pause");
        break;
case 4: cout<<"\nRecorrido en preorden: ";
        Preorden(arbol);// invocamos la funcion para recorrido preorden
        cout<<"\n\n";
        system("pause");
        break;
case 5: cout<<"\nRecorrido en Inorden: ";
        Inorden(arbol); // invocamos la funcion para recorrido inorden
        cout<<"\n\n";
        system("pause");
        break;
case 6: cout<<"\nRecorrido en Postorden: ";
        Postorden(arbol); // invocamos la funcion para recorrido inorden
        cout<<"\n\n";
        system("pause");
        break;
case 7: cout<<"\nDigite el numero a eliminar: ";
        cin>>dato;
        Eliminar(arbol,dato);
        cout<<"\n\n";
        system("pause");
        break;
}
system("cls");
}while(opcion != 8);
}


//funcion crear nuevo nodo
Nodo *crearNodo(int a,Nodo *padre){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = a;
    nuevo_nodo->derecha = NULL;
    nuevo_nodo->izquierda = NULL;
    nuevo_nodo->padre = padre;
    return nuevo_nodo;
}

// funcion para insertar hijos al arbol
void insertarNodo(Nodo *&arbol, int a,Nodo *padre){
      if(arbol == NULL){ //si el arbol esta vacio creamos un nodo
       Nodo *nuevo_nodo = crearNodo(a,padre);
       arbol = nuevo_nodo;

      }else{ //si el arbol tiene un nodo o mas de un nodo
          int valorRaiz = arbol->dato; // valor de la raiz
          if(a < valorRaiz){// si el valor ingresado es menor a la raiz va para la izquierda
            insertarNodo(arbol->izquierda,a,arbol);

          }else{// si el valor ingresado es mayor a la raiz va para la derecha
               insertarNodo(arbol->derecha,a,arbol);
          }
      }
}

// funcion para mostrar el arbol
void mostrarArbol(Nodo *arbol,int i){
   if ( arbol== NULL){ //si el arbol esta vacio retorna
    return;
   }else{
      mostrarArbol(arbol->derecha, i+1); //muestra el lado derecho del arbol
      for(int x=0; x<i; x++ ){
        cout<<"\t  ";
      }
      cout<<arbol->dato<<endl;
      mostrarArbol(arbol->izquierda, i+1); // muestra el lado izquierdo del arbol
   }
}

// funcion para realizar la busqueda
bool buscarNodo(Nodo *arbol, int a){
    if(arbol == NULL){// si el arbol esta vacio retorna un false
       return false;
    }else if(arbol->dato == a){
          return true;
    }else if(a < arbol->dato){ // busqueda por la izquierda donde estan los valores menores
        return buscarNodo(arbol->izquierda,a);
    }else{//busqueda por la derecha donde estan los valores mayores
        return buscarNodo(arbol->derecha,a);
    }
}

// funcion para recorrido en preorden (raiz, izquierda y derecha)en profundidad
void Preorden(Nodo *arbol){
     if(arbol == NULL){//si el arbol esta vacio retorna
        return;
     }else{// caso contrario realiza el rescorrido en preorden que es  raiz, izquierda y derecha
         cout<< " / " <<arbol->dato;// nodo y separacion para la impresion en pantalla
         Preorden(arbol->izquierda);//funcion recursiva para recorrer el arbol por la izquierda
         Preorden(arbol->derecha);//funcion recurciva para recorrer el arbol por la derecha
     }

}

// funcion para recorrido en inorden (izquierda, raiz y derecha)en profundidad
void Inorden(Nodo *arbol){
    if(arbol == NULL){//si el arbol esta vacio entonces retorna
        return;
    }else{// si el arbol no esta vacion recorre en inorden (izquierda numeros nmenores, raiz y derecha numeros mayores)
        Inorden(arbol->izquierda);// funcion recurciva para el recorrido en inorden por la izquierda
        cout<< " / " <<arbol->dato;// impresion de la Raiz en pantalla con separacion
        Inorden(arbol->derecha);// funcion recursiva para el recorrido en indorden por la parte derecha
    }
}

// funcion recorrido en postorden (izquierda, derecha y raiz) en profundidad
void Postorden(Nodo *arbol){
    if (arbol == NULL){//si el arbol esta vacio entonces retorna
        return;
    }else{
         Postorden(arbol->izquierda);// funcion recurciva para el recorrido en inorden por la izquierda
         Postorden(arbol->derecha);// funcion recursiva para el recorrido en indorden por la parte derecha
         cout<< " / " <<arbol->dato;// impresion de la Raiz en pantalla con separacion
    }
}

// funcion determina el nodo mas izquierdo posible
Nodo *minimo(Nodo *arbol){
     if(arbol==NULL){// si el arbol esta vacio retornamos null
        return NULL;
     }
     if (arbol->izquierda){// si el nodo tiene hijo izquierdo buscaremos lo mas izquierdo posible
        return minimo(arbol->izquierda);
     }else{// si no tiene hijo izquierdo retorna el mismo nodo
        return arbol;
     }
}

// funcion para eliminar
void Eliminar(Nodo *arbol,int a){
    if (arbol==NULL){//si el arbol esta vacio entonces retorna
        return;
    }else if(a<arbol->dato){//si el valor del nodo es menor al valor de la raiz buscara por la izquierda
        Eliminar(arbol->izquierda,a);
    }else if(a>arbol->dato){//si el valor del nodo es mayor al valor de la raiz buscara por la derecha
        Eliminar(arbol->derecha,a);
    }else{// si encontro el valor buscado lo elimina
        EliminarNodo(arbol);
    }
}

// funcion reemplazar dos nodos
void reemplazar(Nodo *arbol, Nodo* nuevoNodo){
    if(arbol->padre){// se asigna al pádre a su nuevo hijo
       if(arbol->dato == arbol->padre->izquierda->dato){// asignacion del nuevo padre por la izquierda
        arbol->padre->izquierda=nuevoNodo;
    }else if (arbol->dato == arbol->padre->derecha->dato){// asignacion del nuevo padre por la derecha
        arbol->padre->derecha = nuevoNodo;
       }
    }
     if(nuevoNodo){//procedemos a asignarle a su nuevo padre
        nuevoNodo->padre = arbol -> padre;
     }
}

// funcion para destruir un nodo
void destruirNodo(Nodo *nodo){
   nodo->izquierda = NULL;// busca por la izquierda el valor ingresado y lo elimina
   nodo ->derecha = NULL;// busca por la izquierda el valor ingresado y lo elimina
   delete nodo;
}


//funcion para eliminar el nodo encontrado con 3 opciones de eliminacion
void EliminarNodo(Nodo *nodoEliminar){
   if(nodoEliminar->izquierda && nodoEliminar->derecha){// buscamos si el nodo tiene hijo derecho e hijo izquierdo
       Nodo *menor = minimo(nodoEliminar->derecha);
       nodoEliminar->dato = menor->dato;
       EliminarNodo(menor);
   }
   else if(nodoEliminar->izquierda){// si tiene hijo izquierdo cumple este condicional
       reemplazar(nodoEliminar, nodoEliminar->izquierda); //ahora se reemplaza el nodo eliminado por el nodo de la izquierda
       destruirNodo(nodoEliminar);
   }else if (nodoEliminar->derecha){//ahora se reemplaza el nodo eliminado por el nodo de la derecha
    reemplazar(nodoEliminar,nodoEliminar->derecha);
    destruirNodo(nodoEliminar);
 }else{//si el nodo es una hoja entonces solo se reemplaza por null
     reemplazar(nodoEliminar,NULL);
     destruirNodo(nodoEliminar);
 }

}



