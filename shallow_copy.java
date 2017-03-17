public class MyClass {

    ArrayList<Integer> arr;
    
    public void add(ArrayList<Integer> array){
        array.add(50);
    }


    public MyClass(){
        this.arr = new ArrayList<Integer>();
    }
    
}


public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        MyClass A = new MyClass();
        MyClass B = new MyClass();
        A=B;
        //shallow copy yapıyor O(1) karmaşıklıkta (Java için)
    }
    
}
