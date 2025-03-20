#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/TextOutputter.h>
#include <cppunit/TextTestProgressListener.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/ui/text/TestRunner.h>


#include <iostream>
#include <string>
#include <fstream>

#include "example.h"  // Este cabeçalho contém a definição da função 'maximo'

using namespace CPPUNIT_NS;  //evita de ter que colocar CPPUNIT_NS::
using namespace std;

class test_maximo : public TestFixture {
    CPPUNIT_TEST_SUITE(test_maximo);    // Inicia a suíte de testes
    CPPUNIT_TEST(test_maximo_1);        // Registra o teste 
    CPPUNIT_TEST(test_maximo_2);        // Registra o teste 
    CPPUNIT_TEST(test_maximo_3);        // Registra o teste 
    CPPUNIT_TEST(test_fatorial_1);        // Registra o teste 
    CPPUNIT_TEST(test_fatorial_2);        // Registra o teste 
    CPPUNIT_TEST(test_fatorial_3);        // Registra o teste 
    CPPUNIT_TEST_SUITE_END();           // Finaliza a suíte de testes

public:
    void test_maximo_1() {
        CPPUNIT_ASSERT_EQUAL(10, maximo(5, 10));  // Verifica se o resultado está correto
    }

    void test_maximo_2() {
        CPPUNIT_ASSERT_EQUAL(3, maximo(3, 3));  // Verifica se o resultado está correto
    }

    void test_maximo_3() {
        CPPUNIT_ASSERT_EQUAL(0, maximo(3, 3));  // Verifica se o resultado está correto
    }

    void test_fatorial_1() {
        CPPUNIT_ASSERT_EQUAL(1, fatorial(0));  // Verifica se o resultado está correto
    }

    void test_fatorial_2() {
        CPPUNIT_ASSERT_EQUAL(1, fatorial(1));  // Verifica se o resultado está correto
    }

    void test_fatorial_3() {
        CPPUNIT_ASSERT_EQUAL(120, fatorial(5));  // Verifica se o resultado está correto
    }


};

CPPUNIT_TEST_SUITE_REGISTRATION(test_maximo);

int main() {
    
    //Configuracoes para armazenar os resultados dos testes
    TestResult testresult;                          //cria objeto para armazenar os resultados dos testes executados
    TestResultCollector collectedresults;           //objeto usado para coletar e armazenar os resultados dos testes
    testresult.addListener(&collectedresults);      //Adiciona collectedresults como listener do objeto testresult.

    //armazenar a lista de testes
    //BriefTestProgressListener progress;             //declara um objeto para guardar o progresso do teste
    //testresult.addListener(&progress);              //Adiciona progress como istener do objeto testresult. 


    //Responsável por executar os testes
    TestRunner testrunner;                                                  //Cria o objeto que executa os testes
    testrunner.addTest(TestFactoryRegistry::getRegistry().makeTest());
    testrunner.run(testresult);                                             //Executa os testes e armazena os resultados em testresult

    //mostrar os resultados no terminal
    TextOutputter textOutputter(&collectedresults, cout);
    textOutputter.write();


    //para exportar os resultados em um arquivo XML
    //ofstream xmlFileOut("example_1_test.xml");                      //Criar o arquivo XML 
    //XmlOutputter xmlOut(&collectedresults, xmlFileOut);             //Associa o arquivo aos resultados de teste
    //xmlOut.write();                                                 //escreve os resultados nesse teste


    return collectedresults.wasSuccessful()? 0 : 1;

    return 0;
}