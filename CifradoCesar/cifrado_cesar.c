
#include <jni.h>
#include "CifradoCesar.h"
#include <string.h>

// Función para cifrar usando el cifrado César
JNIEXPORT jstring JNICALL Java_CifradoCesar_cifrar(JNIEnv *env, jobject obj, jstring texto, jint desplazamiento) {
    const char *textoOriginal = (*env)->GetStringUTFChars(env, texto, 0);
    int len = strlen(textoOriginal);
    char textoCifrado[len + 1];

    for (int i = 0; i < len; i++) {
        textoCifrado[i] = textoOriginal[i] + desplazamiento;
    }
    textoCifrado[len] = '\0';

    (*env)->ReleaseStringUTFChars(env, texto, textoOriginal);
    return (*env)->NewStringUTF(env, textoCifrado);
}

// Función para descifrar usando el cifrado César
JNIEXPORT jstring JNICALL Java_CifradoCesar_descifrar(JNIEnv *env, jobject obj, jstring texto, jint desplazamiento) {
    const char *textoOriginal = (*env)->GetStringUTFChars(env, texto, 0);
    int len = strlen(textoOriginal);
    char textoDescifrado[len + 1];

    for (int i = 0; i < len; i++) {
        textoDescifrado[i] = textoOriginal[i] - desplazamiento;
    }
    textoDescifrado[len] = '\0';

    (*env)->ReleaseStringUTFChars(env, texto, textoOriginal);
    return (*env)->NewStringUTF(env, textoDescifrado);
}

