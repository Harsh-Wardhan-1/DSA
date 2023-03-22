import java.util.Arrays;
import java.util.ArrayList;

class solution {
    private void add(ArrayList<Integer> a) {
        // arr[1] = 3;
        a.set(1, 4);
    }

    public static void main(String[] args) {
        solution obj = new solution();
        // int arr[] = { 1, 2, 3 };
        ArrayList<Integer> a = new ArrayList<>();
        a.add(1);
        a.add(2);
        a.add(3);
        obj.add(a);
        System.out.println(a);
    }
}