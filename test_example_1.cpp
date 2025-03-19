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

#include <iostream>
#include <string>
#include <fstream>
#include "example_1.h"  // Este cabeçalho contém a definição da função 'maximo'


using namespace std;

class test_maximo : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(test_maximo);    // Inicia a suíte de testes
    CPPUNIT_TEST(test_maximo_1);        // Registra o teste 
    CPPUNIT_TEST(test_maximo_2);        // Registra o teste 
    CPPUNIT_TEST(test_maximo_3);        // Registra o teste 
    CPPUNIT_TEST_SUITE_END();           // Finaliza a suíte de testes

public:
    void test_maximo_1() {
        CPPUNIT_ASSERT_EQUAL(10, maximo(5, 10));  // Verifica se o resultado está correto
    }

    void test_maximo_2() {
        CPPUNIT_ASSERT_EQUAL(3, maximo(3, 3));  // Verifica se o resultado está correto
    }

    void test_maximo_3() {
        CPPUNIT_ASSERT_EQUAL(3, maximo(3, 3));  // Verifica se o resultado está correto
    }

    void setUp() {
        // Código para configurar o ambiente de teste, se necessário
    }

    void tearDown() {
        // Código para limpar depois dos testes, se necessário
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_maximo);

int main() {
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener(&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener(&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("example_1_test.xml");
    CppUnit::XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}