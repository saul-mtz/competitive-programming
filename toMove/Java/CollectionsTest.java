import java.lang.Integer;
import java.lang.System;
import java.util.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeMap;

public class CollectionsTest {


    protected static List sort(List c) {
        java.util.Collections.sort(c);
        return c;
    }

    protected static void arrayList() {

        System.out.println("java.util.ArrayList");
        List<Double> testList = new ArrayList();

        testList.add(0.5);
        testList.add(0.2);
        testList.add(0.9);
        testList.add(0.1);
        testList.add(0.1);
        testList.add(0.1);


        System.out.print("for-each [");
        for (Double number : testList) {
            System.out.printf("%.1f ", number);
        }
        System.out.println("]");

        System.out.print("Iterator [");
        Iterator<Double> it = testList.iterator();
        while (it.hasNext()) {
            System.out.printf("%.1f ", it.next());
        }
        System.out.println("]");

        System.out.println("Sorted ArrayList: " + sort(testList));
        System.out.println("look for 0.3: " + Collections.binarySearch(testList, 0.3));
        System.out.println("look for 0.1: " + Collections.binarySearch(testList, 0.1) + ", " + testList.get(2));
        System.out.println("look for 0.5: " + Collections.binarySearch(testList, 0.5) + ", " + testList.get(4));

        Collections.reverse(testList);
        System.out.println("Reversed: " + testList);

        Collections.shuffle(testList);
        System.out.println("Shuffled: " + testList);
    }

    protected static void treeMap() {
        System.out.println("java.util.TreeMap;");
        Map<Integer, String> testMap = new TreeMap<>();
        testMap.put(3, "Tres");
        testMap.put(1, "Uno");
        testMap.put(5, "Cinco");
        testMap.put(55, "50 y cinco");
        testMap.put(1000, "Mil");
        testMap.put(120, "Ciento veinte");
        System.out.println(testMap);
    }

    protected static void hashMap() {
        System.out.println("java.util.HashMap");
        Map<Integer, String> testMap = new HashMap<>();

        testMap.put(3, "Tres");
        testMap.put(1, "Uno");
        testMap.put(5, "Cinco");
        testMap.put(55, "50 y cinco");
        testMap.put(1000, "Mil");
        testMap.put(120, "Ciento veinte");


        System.out.print("for-each [");

        for (Entry<Integer, String> e : testMap.entrySet()) {
            System.out.printf("(%d, %s) ", e.getKey(), e.getValue());
        }
        System.out.println("]");

        System.out.print("Iterator [");
        Iterator<Entry<Integer, String>> it = testMap.entrySet().iterator();
        while (it.hasNext()) {
            Entry <Integer, String> e = it.next();
            System.out.printf("(%d, %s) ", e.getKey(), e.getValue());
        }
        System.out.println("]");

        //Collections.sort(testMap.keySet());
        Set<Integer> copyEntry = testMap.keySet();
        System.out.println("Sorted Keys: " + copyEntry);
        System.out.println("Map: " + testMap);
        //System.out.println("Sorted ArrayList: " + testMap);
        /*
        System.out.println("look for 0.3: " + Collections.binarySearch(testMap, 0.3));
        System.out.println("look for 0.1: " + Collections.binarySearch(testMap, 0.1) + ", " + testMap.get(2));
        System.out.println("look for 0.5: " + Collections.binarySearch(testMap, 0.5) + ", " + testMap.get(4));

        Collections.reverse(testMap);
        System.out.println("Reversed: " + testMap);

        Collections.shuffle(testMap);
        System.out.println("Shuffled: " + testMap);
        */
    }

    public static void main (String[] args) {
        arrayList();
        hashMap();
        treeMap();
    }
}