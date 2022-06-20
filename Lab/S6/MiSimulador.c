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



/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
 void init_cache ()
 {
 	/* Escriu aqui el teu codi */

   for (int i = 0; i < 128; ++i) {
     v[i].valid = 0;
   }
   //total_hits = 0;
   //total_misses = 0;
 }

/* La rutina reference es cridada per cada referencia a simular */
void reference (unsigned int address, unsigned int LE) /*0: Lectura, 1: Escriptura*/
{
	unsigned int byte;
	unsigned int bloque_m;
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;
	unsigned int lec_mp;
	unsigned int mida_lec_mp;
	unsigned int esc_mp;
	unsigned int mida_esc_mp;
	unsigned int replacement;
	unsigned int tag_out;

	/* Escriu aqui el teu codi */
	byte = address%32;
  bloque_m = address/32;
  linea_mc = bloque_m%128;
  tag = bloque_m/128;

  miss = v[linea_mc].valid == 0 || v[linea_mc].tag != tag;
  replacement = miss && v[linea_mc].valid == 1 && !LE;

  if (!LE) {
    //LECTURA
    mida_esc_mp = 0;
    esc_mp = 0;

    //MISS LECTURA
    if (miss) {
      mida_lec_mp = 32;
      lec_mp = 1;
      if (replacement) {
        tag_out = v[linea_mc].tag;
        v[linea_mc].tag = tag;
      }
      else {
        v[linea_mc].valid = 1;
        v[linea_mc].tag = tag;
      }
    }
    //HIT LECTURA
    else {
      mida_lec_mp = 0;
      lec_mp = 0;
    }
  }
  //ESCRIPTURA
  else {
    mida_esc_mp = 1;
    esc_mp = 1;
    mida_lec_mp = 0;
    lec_mp = 0;
  }



	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual
	 * */
	test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
			miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
			replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */
void final ()
{
 	/* Escriu aqui el teu codi */
	//printf("Hits %d\n", total_hits);
	//printf("Misses %d\n\n", total_misses);

}
