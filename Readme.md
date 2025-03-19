## Cpp Unit

O CPPUnit é um framework de testes unitários para C++ baseado no Junit. 



## Intalação e pré Requisitos

Para instalar o CPP Unit no Linux - Ubuntu utilizar o comando abaixo dentro do seu repositório.

        sudo apt update
        sudo apt install libcppunit-dev

## Tutorial

A criação de uma suíte de testes utilizando o CppUnit, se resume a:

1. Criar um novo arquivo de teste;
2. Importar nesse arquivo as funções que devem ser testadas;
3. Importar as bibliotecas do CppUnit;
4. Escrever a Suite de Testes;
5. Compilar a Suite utilizando o GPP.
6. Executar a Suite.

### Criação da Classe de Testes

O CppUnit Adota uma programação orientada a objetos para criar os testes. Assim, para começar deve-se definir uma classe de teste. É nessa classe onde iremos escrever todas as rotinas de testes. Definido a classe podemos iniciar a definição dos testes. Para isso são criadas funções. Para padronizar sempre começamos o nome da função de teste com "test_". Em seguida dentro dessas funções definimos os elementos do teste. Entre esses elementos o principal é a chamada de CPPUNIT_ASSERT_EQUAL(), que irá fazer a comparação do valor esperado do teste com o valor retornado pela função.

                class test_meuTeste : public TestFixture      //definição da Classe de teste
                {
                        CPPUNIT_TEST_SUITE(test_meuTeste);    // Inicia a suíte de testes
                        CPPUNIT_TEST(test_1);                 // "Registra" o teste 1
                        CPPUNIT_TEST(test_2);                 // "Registra" o teste 2 
                        CPPUNIT_TEST_SUITE_END();             // Finaliza a suíte de testes

                        public:
                        void test_1()                                                        
                        {
                                CPPUNIT_ASSERT_EQUAL(Resultado_Esperado, funcao_testada());  
                        }

                        void test_2()                                                        
                        {
                                CPPUNIT_ASSERT_EQUAL(Resultado_Esperado, funcao_testada());  
                        }
                };



### Programação na Main()

Feito a definição das classe e dos testes podemos escrever a int main. É nela que iremos definir a execução dos testes e quais dados serão coletados do teste. Assim definimos inicialmente um Objeto testresul ligado ao armazenamento dos resultados dos testes executados.

                TestResult testresult;                         



Para armazenar os testes temos 2 opções. Se desejamos apenas mostrar a quantidade de testes que falhou no fim da execução utilizamos o BriefTestProgressListener. Ele pode ser criado e associado ao test Result com as linhas de código abaixo:

                BriefTestProgressListener progress;         
                testresult.addListener(&progress);             

Essas configurações geram um output no seguinte formato:


Agora se desejamos um relatório mais detalhadado, mostrando por exemplo com detalhes o teste que falhou utilizamos o objeto TestResultCollector:

                TestResultCollector collectedresults;         
                testresult.addListener(&collectedresults);     

Essas configurações geram um output no seguinte formato:




Definido o que será coletado, podemos partir para execução de fato do teste dentro da main. Ela é feita pela criação de um objeto TestRunner, associação dos testes a esse objeto e chamada da função .run que executa os testes e armazena os resultados no objeto result.

                TestRunner testrunner;                                                 
                testrunner.addTest(TestFactoryRegistry::getRegistry().makeTest());
                testrunner.run(testresult);                                             

Executado os testes temos a opção de gravar os seus resultado em um arquivo .xml

                ofstream xmlFileOut("nome_do_arquivo.xml");                      
                XmlOutputter xmlOut(&collectedresults, xmlFileOut);              
                xmlOut.write();                                              


## Exemplo

Para demonstrar a ferramenta foi criado um exemplo básico de um conjunto de 3 funções: Máximo, ParImpar e fatorial. Ele encontra-se com a seguinte estrutrura

- example_1.cpp : contém o código com as funções a ser testado
- example_1.h : header para o código com as funções
- test_example:1.cpp : contém o código com a rotina de testes
- Makefile

Para utilizar o makefile utilizar os comandos para compilar e executar os testes.

                make clean
                make 
                make run 



## Análise da Ferramenta

### Aspectos Positivos da Ferramenta

- Execução automática dos testes;
- Relativamente fácil de implementar os testes;
- Exporta os resultados para .xml

### Aspectos Negativos da Ferramenta

- Ela não mostra cobertura de código;
- Existe uma curva inicial de aprendizado para utilizar, porém depois que aprende fica fácil.
        