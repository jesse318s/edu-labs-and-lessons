import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.Test;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

public class AppTest {
    @Test
    public void testMainOutput() throws Exception {
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        PrintStream originalOut = System.out;

        System.setOut(new PrintStream(outContent));

        try {
            App.main(new String[] {});
            String output = outContent.toString();
            
            // Test basic arithmetic output
            assertTrue(output.contains("3"));
            assertTrue(output.contains("-1"));
            
            // Test conditional output
            assertTrue(output.contains("a + b is equal to 3"));
            
            // Test loop output
            assertTrue(output.contains("i = 5"));
            assertTrue(output.contains("i = 1"));
            
            // Test function output
            assertTrue(output.contains("3"));
            
            // Test OOP output
            assertTrue(output.contains("Hello, World!"));
            assertTrue(output.contains("isSpecial: true"));
            assertTrue(output.contains("isSpecial: false"));
            assertTrue(output.contains("Number of HelloWorld objects: 2"));
        } finally {
            System.setOut(originalOut);
        }
    }

    @Test
    public void testAddFunction() {
        assertEquals(5, App.add(2, 3));
        assertEquals(0, App.add(-1, 1));
        assertEquals(-5, App.add(-2, -3));
    }
}