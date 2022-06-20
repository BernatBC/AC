#include "CacheSim.h"
//#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

 struct cache{
   unsigned int valid;
   unsigned int tag;
 };

struct cache v[128];

//int total_hits;
//int total_misses;


/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */

  for (int i = 0; i < 128; ++i) {
    v[i].valid = 0;
  }
  //total_hits = 0;
  //total_misses = 0;
}

/* La rutina reference es cridada per cada referencia a simular */
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m;
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reempla�a una linia valida
	unsigned int tag_out;	   // TAG de la linia reempla�ada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)

	t1=GetTime();
	/* Escriu aqui el teu codi */

  byte = address%32;
  bloque_m = address/32;
  linea_mc = bloque_m%128;
  tag = bloque_m/128;

  miss = v[linea_mc].valid == 0 || v[linea_mc].tag != tag;
  replacement = miss && v[linea_mc].valid == 1;

  if (miss) {
    if (replacement) {
      tag_out = v[linea_mc].tag;
      v[linea_mc].tag = tag;
    }
    else {
      v[linea_mc].valid = 1;
      v[linea_mc].tag = tag;
    }
  }
/*
  if (!miss) ++total_hits;
  else ++total_misses;*/

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb� mesurem el temps d'execuci�
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print (address, byte, bloque_m, linea_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */
void final ()
{
 	/* Escriu aqui el teu codi */
  //printf("Hits %d\n", total_hits);
  //printf("Misses %d\n\n", total_misses);

}
