#include <iostream>
#include <iomanip>
# include <map>

class ArgumentParser
{
public:
    void RegisterFlag(const std::string& flag)
    {
         if(!flag.empty())
        {
            m_Flags[flag]=false;

        }
        

    }
    bool GetFlag(const std::string &flag)
    {
       return false;
    }

    void Parse(int argc, char *argv[])
    {
    }

private:
    std::map<std::string,bool> m_Flags;// dicionário que recebe como key a flag em string , e um booleano
};

int main(int argc, char *argv[])

/*argumento passados pela linha de comandos
 0-caminho do executável
 1- --nome
 2- "passar nome do ficheiro  "*/

{
    setlocale(LC_ALL, "PT-PT"); // acentuação no texto e caracteres especiais

    ArgumentParser argParser;

    argParser.RegisterFlag("rename");
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
