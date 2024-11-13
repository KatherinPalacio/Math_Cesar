public class CifradoCesar {
    static {
        System.loadLibrary("cifrado_cesar");
    }

    public native String cifrar(String texto, int desplazamiento);
    public native String descifrar(String texto, int desplazamiento);
}

