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
                        //Example:--rename
                        arg=arg.substr(2);//subtrai os dois primeiros caracteres. Retira o --
                        //Example:rename
                        if (arg.find_first_of('=') != std::string::npos) // função para encontrar a primeira ocorrencia de "=", e for diferente da pos 
					    {
						// é uma opção
						const size_t equalsignPos = arg.find('='); // Encontrar a posição onde o caratere "=" está na string ARG

						if (equalsignPos != std::string::npos) // verifica se existe o "=" na opcao
						{/*
							// dividir a opcão em chave e valor
							std::string optioname = arg.substr(0, equalsignPos); // vai separar a string do inicio até ao igual
							std::string optionValue = arg.substr(equalsignPos + 1);// vai buscar o caratere após o sinal igual

							auto optionIt = m_opcao.find(optioname);

							if (optionIt != std::end(m_opcao))
							{
								//achou uma opcao registada
								optionIt->second = optionValue;
							}*/
						}
					}

					else
					{
						// é uma flag	
						auto flagit = m_flags.find(arg); // encontrar o argumento

						if (flagit != end(m_flags))
						{ 
							//achei uma flag resgistada marcar como verdadeiro
							flagit->second = true;
						}
					}
                        
                        
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
