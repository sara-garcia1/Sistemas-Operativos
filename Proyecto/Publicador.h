#ifndef PUBLICADOR_H
#define PUBLICADOR_H

bool validarFormatoNoticia(const char* noticia);
void publicarNoticia(int pipe, const char* noticia);
void ejecutarPublicador(const char* pipePSC, const char* archivoNoticias, int tiempo);

#endif // PUBLICADOR_H

