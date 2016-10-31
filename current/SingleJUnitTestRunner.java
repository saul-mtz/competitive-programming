import org.junit.Test;

import java.io.ByteArrayOutputStream;

public class SingleJUnitTestRunner {

    private static final ByteArrayOutputStream outContent = new ByteArrayOutputStream();

    @Test
    public static void main(String... args) throws ClassNotFoundException {
        Solution solutionClass = new Solution();/*
        Assert.assertEquals(solutionClass.bliny2(3), 5);
        Assert.assertEquals(solutionClass.bliny2(4), 796);*/
    }
}