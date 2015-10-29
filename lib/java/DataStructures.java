import java.lang.Exception;
import java.lang.String;
import java.lang.System;
import java.lang.reflect.Method;
import java.util.*;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Stack;

/**
 * Example of how to use basic java built-in data structures
 */
class DataStructures {

    static void arrayListDemo() {

        System.out.println("java.util.ArrayList<String>");

        ArrayList<String> list = new ArrayList<>();
        list.add("String 1");
        list.add("String 2");
        list.add("String 5");
        list.add("String 4");

        printArrayList(list);

        list.remove(list.size()-1); // remove the last element
        list.remove(0); // remove the first
        printArrayList(list);

        System.out.println("Sorted list");
        Collections.sort(list);
        printArrayList(list);

        System.out.println("Binary search for 'String 2': " + Collections.binarySearch(list, "String 2"));
        System.out.println("Binary search for 'String 5': " + Collections.binarySearch(list, "String 5"));
        System.out.println("Binary search for 'String 25': " + Collections.binarySearch(list, "String 25"));
    }

    static void queueDemo() {

        System.out.println("java.util.LinkedList<String>");

        LinkedList<String> q = new LinkedList<>();
        q.offer("String 1");
        q.offer("String 2");
        q.offer("String 3");
        q.offer("String 4");

        printArrayList(q);

        System.out.println("peek does not remove the head");
        q.peek();
        printArrayList(q);

        System.out.println("poll does remove the head");
        q.poll();
        printArrayList(q);
    }

    static void stackDemo() {

        System.out.println("java.util.Stack<String>");

        Stack<String> q = new Stack<>();
        q.push("String 1");
        q.push("String 2");
        q.push("String 3");
        printArrayList(q);

        System.out.println("pop does remove the head");
        q.pop();
        printArrayList(q);
        q.pop();
        printArrayList(q);
        q.pop();
        printArrayList(q);
    }

    static void hashMapDemo() {

        System.out.println("java.util.HashMap<String, String>");

        java.util.HashMap<String, String> h = new HashMap<>();
        h.put("Key1", "Value 1");
        h.put("Key2", "Value 2");
        h.put("Key3", "Value 3");
        h.put("Key4", "Value 4");

        Iterator<String> keySetIterator = h.keySet().iterator();
        while(keySetIterator.hasNext()) {
            String key = keySetIterator.next();
            System.out.println("key: " + key + " value: " + h.get(key));
        }

        System.out.println("HashMap[Key1] = " + h.get("Key1"));
        System.out.println("Is Key2 in the HashMap?: " + h.containsKey("Key2"));
        System.out.println("Is Value 4 in the HashMap?: " + h.containsValue("Value 4"));
    }

    /**
     * Print the elements of an array list
     */
    static void printArrayList(Collection<String> l) {
        int i;
        Class<?> c = l.getClass();
        String methodName = null;
        boolean args = true;

        switch (c.getName()) {
            case "java.util.ArrayList":
                methodName = "get";
                break;
            case "java.util.LinkedList":
                methodName = "get";
                break;
            case "java.util.Stack":
                methodName = "peek";
                args = false;
                break;
            default:
                System.out.println(c.getName());
        }

        try {
            Method method = null;

            if (args) {
                method = c.getMethod(methodName, int.class);
            } else {
                method = c.getMethod(methodName);
            }

            for (i = 0; i < l.size(); i ++) {
                if (args) {
                    System.out.println(method.invoke(l, i));
                } else {
                    System.out.println(method.invoke(l));
                }
            }
            System.out.println(i + " elements found.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        arrayListDemo();
        System.out.println();
        queueDemo();
        System.out.println();
        stackDemo();
        System.out.println();
        hashMapDemo();
    }
}