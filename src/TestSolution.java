import java.io.*;
import java.nio.file.*;

import static org.junit.Assert.assertEquals;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;


/**
 * @author saul.mtz.v
 */
public class TestSolution {

    private final ByteArrayOutputStream outContent = new ByteArrayOutputStream();

    @Before
    public void setUpStreams() {
        System.setOut(new PrintStream(outContent));
    }

    @After
    public void cleanUpStreams() {
        System.setOut(null);
    }

    @Test
    public void evaluatesExpression() {
        String inputFilesDir = "src";
        Path dir = Paths.get(inputFilesDir);

        try (DirectoryStream<Path> stream = Files.newDirectoryStream(dir, "input*")) {
            for (Path entry: stream) {
                // each input file must have an output one with the same suffix
                String outputFileName = "output" + entry.getFileName().toString().split("input")[1];

                // does the output file exists?
                boolean outFileExists = new File(inputFilesDir, outputFileName).exists();

                if (outFileExists) {
                    //System.out.println("Testing " + entry.getFileName());

                    // input data
                    String content = new String(Files.readAllBytes(entry));
                    ByteArrayInputStream in = new ByteArrayInputStream(content.getBytes());
                    System.setIn(in);

                    // expected output string
                    String expectedOut = new String(Files.readAllBytes(Paths.get(inputFilesDir, outputFileName)));

                    // run the test
                    Solution.main(new String[]{});

                    // compare the input with the expected ouput
                    assertEquals(expectedOut.trim(), outContent.toString().trim());
                    outContent.reset();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}