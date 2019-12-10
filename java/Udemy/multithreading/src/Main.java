public class Main {
    public static void main(String[] args) throws InterruptedException{
        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println("Inside the run : "+Thread.currentThread().getName());
                System.out.println("Thread priority is : "+Thread.currentThread().getPriority() );
                /*throw new RuntimeException("Intentional exception");*/
            }
        });

        /*thread.setName("Exception thread");
        thread.setUncaughtExceptionHandler(new Thread.UncaughtExceptionHandler() {
            @Override
            public void uncaughtException(Thread thread, Throwable throwable) {
                System.out.println("Exception occured in thread : "+thread.getName()+" with message : "+throwable.getMessage());
            }
        });*/
        thread.setName(" New my thread ");
        thread.setPriority(Thread.MAX_PRIORITY);
        System.out.println("Before starting thread : "+Thread.currentThread().getName());
        thread.start();
        System.out.println("After starting thread : "+Thread.currentThread().getName());
//        Thread.sleep(10000);
    }
}
