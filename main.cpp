#include <iostream>
#include <iomanip>
# include <map>

class ArgumentParser
{
public:
    void RegisterFlag(const std::string& flag) // metodo register - regista e gurda as flag´s
    {
         if(!flag.empty())
        {
            m_flags[flag]=false;
 
        }
        

    }
    bool GetFlag(const std::string &flag) const
    {
        if(!flag.empty())// check if flag have something / Can´t is empty
        {
            auto flagit = m_flags.find(flag); //function that finds flag inside the dictionary / associate an iterator that will go through dictionary 
            if(flagit!=std::end(m_flags))// verifica se o valor é valido - se ta dentro dos valores possiveis do dicionário
            {
            return flagit->second; //return o valor associado a chave
            }
        }
       return false;
    }

    void Parse(int argc, char *argv[])
    {
        if(argc>1) // verifica se tem mais que 1 argumento
        {
            for(int i=1; i>argc ;i++) // percorre os argumentos
            {
                std::string arg = argv[i]; // guarda argv numa string

                if(arg.length()>=3)   // verifica se é uma flag - toda flag começa por -- e um carater, logo tem de 3 caracteres
                {                     // flag válida

                    if(arg[0] =='-' && arg[1] =='-') // 2 primeiros elementos são --
                    {
                        

                    }

                }         

            }


        }
    }

private:
    std::map<std::string,bool> m_flags;//  Dictionary that receives as key the flag in string and a bool 
};

int main(int argc, char *argv[])

/*argumento passados pela linha de comandos
 0-caminho do executável
 1- --nome
 2- "passar nome do ficheiro  "*/

{
    setlocale(LC_ALL, "PT-PT"); // acentuação no texto e caracteres especiais

    ArgumentParser argParser;

    argParser.RegisterFlag("rename"); // regista a flag
    argParser.RegisterFlag("convert");
    argParser.RegisterFlag("resize");
    argParser.RegisterFlag("scale");
    //argParser.RegisterFlag("folder");
    //argParser.RegisterFlag("amount");

    argParser.Parse(argc, argv);

    std::cout << std::boolalpha << "rename: " << argParser.GetFlag("rename") << std::endl;
    std::cout << std::boolalpha << "convert: " << argParser.GetFlag("convert") << std::endl;
    std::cout << std::boolalpha <<"resize: " << argParser.GetFlag("resize") << std::endl;
    std::cout << std::boolalpha <<"scale: " << argParser.GetFlag("scale") << std::endl;
    //cout << "Folder : " << pssgemarg.getopcao("folder") << endl;
    //cout << "Amount : " << pssgemarg.getopcao("amount") << endl;

    return 0;
}
