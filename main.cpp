#include <iostream>


int main(int argc, char* argv[]) 

/*argumento passados pela linha de comandos
 0-caminho do executável
 1- --nome
 2- "passar nome do ficheiro  "*/

{
    setlocale(LC_ALL, "pt-pt");
    for(int i=0;i<argc;i++)
    {
        
        std::cout<<argv[i]<<std::endl;
    }

return 0;
 
}