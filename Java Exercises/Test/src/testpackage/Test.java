package testpackage;

import java.util.logging.Logger;

public class Test {
    private static final Logger logger = Logger.getLogger(Test.class.getName());

    public void testMethod() {
        logger.info("This is a test method.");
    }
    public static void main(String[] args) {
        logger.info("Hello World!");
        Test test = new Test();
        test.testMethod();
    }
}
