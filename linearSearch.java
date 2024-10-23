import java.util.Scanner;

public class linearSearch {
    public static int search(int arr[], int element) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return 0;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = {4, 12, 34, 45, 67, 86, 98, 121, 323, 344};
        int element;
        System.out.println("enter element to search: ");
        element = sc.nextInt();
        int index = search(arr, element);
        sc.close();
        if (search(arr, element) == 0) {
            System.out.println("ELEMENT NOT FOUND!!");
        }
        else{
            System.out.printf("ELEMENT FOUND AT INDEX %d",index);
        }
    }
}
