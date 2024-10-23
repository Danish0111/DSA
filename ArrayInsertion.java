import java.util.Scanner;

public class ArrayInsertion {
    public static int insertion(int arr[], int index, int value, int size, int capacity){
        for (int i = size; i >= index ; i--) {
            arr[i+1] = arr[i];
        }
        size++;
        arr[index] = value;
        return size;
    }
    
    public static void display(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            System.out.printf("%d ", arr[i]);
        }
    }
    public static void main(String[] args) {
        int size = 5;
        int[] arr = new int[100];
        arr[0] = 32;
        arr[1] = 12;
        arr[2] = 2;
        arr[3] = 5;
        arr[4] = 20;
        int index; 
        System.out.println("enter the index you want insertion: ");
        Scanner sc = new Scanner(System.in);
        index = sc.nextInt();

        int value; 
        System.out.println("enter the value: ");
        value = sc.nextInt();

        sc.close();
        size = insertion(arr, index, value, size, 100);
        display(arr, size);
    }
}