## CppUnit

O [CppUnit](https://cppunit.sourceforge.net/doc/cvs/index.html) é um framework de testes unitários para C++ baseado no JUnit para Java. 

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
5. Compilar a Suite utilizando o g++.
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

Efetivamente antes da main deve-se registra a classe de testes no CPPUnit utilizando:

                CPPUNIT_TEST_SUITE_REGISTRATION(test_meuTeste);


Feito a definição das classe e dos testes podemos escrever a int main. É nela que iremos definir a execução dos testes e quais dados serão coletados do teste. Assim definimos inicialmente um Objeto testresul ligado ao armazenamento dos resultados dos testes executados.

                TestResult testresult;                    //objeto para armazenar os resultados
                TestResultCollector collectedresults;     //objeto usado para coletar os resultados 
                testresult.addListener(&collectedresults);                              


Por padrão o CPPUnit vai mostrar apenas um resumo com quais testes falaharam, e porque falharam. Abaixo temos um exemplo de um output no terminal:

                !!!FAILURES!!!
                Test Results:
                Run:  6   Failures: 1   Errors: 0


                1) test: test_maximo::test_maximo_3 (F) line: 47 test_example.cpp
                equality assertion failed
                - Expected: 0
                - Actual  : 3


Se desejamos mostrar uma lista com todos os testes podemos utilizar o BriefTestProgressListener. Ele pode ser criado e associado ao test Result com as linhas de código abaixo:

                BriefTestProgressListener progress;         
                testresult.addListener(&progress);             

Essas configurações permitem gerar o output abaixo com o nome do teste e o status, sendo o "OK" interpretado como passou no teste e "assertion" como falhou no teste:

                test_maximo::test_maximo_1 : OK
                test_maximo::test_maximo_2 : OK
                test_maximo::test_maximo_3 : assertion
                test_maximo::test_fatorial_1 : OK
                test_maximo::test_fatorial_2 : OK
                test_maximo::test_fatorial_3 : OK


Definido o que será coletado, podemos partir para execução de fato do teste dentro da main. Ela é feita pela criação de um objeto TestRunner, associação dos testes a esse objeto e chamada da função .run que executa os testes e armazena os resultados no objeto result.

                TestRunner testrunner;                                                 
                testrunner.addTest(TestFactoryRegistry::getRegistry().makeTest());
                testrunner.run(testresult);                                             

Após chamar os comando que executam os testes temos 2 opções para observar os resultados dos testes. A primeira é de mostrar os resultados no terminal. Para isso precisamos utilizar o código abaixo:

                TextOutputter textOutputter(&collectedresults, cout);
                textOutputter.write();


A 2° opção é de gravar os seus resultado em um arquivo .xml com o código abaixo:

                ofstream xmlFileOut("nome_do_arquivo.xml");                      
                XmlOutputter xmlOut(&collectedresults, xmlFileOut);              
                xmlOut.write();                                              


## Exemplo

Para demonstrar a ferramenta foi criado um exemplo básico de um conjunto de 2 funções: Máximo e fatorial. Ele encontra-se com a seguinte estrutrura

- example.cpp : contém o código com as funções a ser testado
- example.h : header para o código com as funções
- test_example:.cpp : contém o código com a rotina de testes
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
        
