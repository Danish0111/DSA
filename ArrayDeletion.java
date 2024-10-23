import java.util.Scanner;

public class ArrayDeletion {
    public static int deletion(int arr[], int index, int size, int capacity){
        for (int i = index; i < size ; i++) {
            arr[i] = arr[i+1];
        }
        size--;
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
        System.out.println("enter the index you want to delete: ");
        Scanner sc = new Scanner(System.in);
        index = sc.nextInt();
        sc.close();
        size = deletion(arr, index, size, 100);
        display(arr, size);
    }
}
