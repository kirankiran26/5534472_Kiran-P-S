import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    public static void miniMaxSum(List<Integer> arr) {
        long min = Integer.MAX_VALUE;
        long max = Integer.MIN_VALUE;
        long totalsum = 0;
        for (int currnum : arr) {
            if (currnum < min)
                min = currnum;
            if (currnum > max)
                max = currnum;
            totalsum += currnum;
        }
        long minsum = totalsum - max;
        long maxsum = totalsum - min;
        System.out.println(minsum + " " + maxsum);
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                .map(Integer::parseInt)
                .collect(toList());

        Result.miniMaxSum(arr);

        bufferedReader.close();
    }
}
