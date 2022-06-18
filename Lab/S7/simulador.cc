#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


 struct linia_cache{
   unsigned int valid;
   unsigned int tag;
 };

int mida_linia;
int mida_cache;
int cache_lines;
vector<linia_cache> cache;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
	/* Escriu aqui el teu codi */
  for (int i = 0; i < cache_lines; ++i)
  {
    cache[i].valid = 0;
    cache[i].tag = 0;
  }
}


/* La rutina reference es cridada per cada referencia a simular */
bool reference (int address) // Return true si HIT, false si MISS
{
	// unsigned int byte = (address%linia_cache); // We get last 5 bits as offset
	int bloque_m = address/mida_linia;
	unsigned int linea_mc = (bloque_m%cache.size());  // Last bits of bloque_m
	unsigned int tag = (bloque_m/cache.size()); // Delete linea_mc from bloque_m to get the tag

	unsigned int miss;	   // boolea que ens indica si es miss
	//unsigned int replacement;  // boolea que indica si es reempla�a una linia valida
	//unsigned int tag_out;	   // TAG de la linia reempla�ada

	/* Escriu aqui el teu codi */
  // cout << address << " / " << mida_linia << endl;
  // cout << bloque_m << " % " << cache.size()<< endl;
  // cout << linea_mc << endl << " --------------- " << endl;
  if (cache[linea_mc].valid == 0)
  {
    cache[linea_mc].valid = 1;
    cache[linea_mc].tag = tag;
    miss = true;
    //replacement = false;
  }
  else if (cache[linea_mc].tag == tag)
  {
    miss = false;
    //replacement = false;
  }
  else
  {
    //tag_out = cache[linea_mc].tag;
    cache[linea_mc].tag = tag;
    miss = true;
    //replacement = true;
  }
  return not miss;
}

/* La rutina final es cridada al final de la simulacio */
void final ()
{
 	/* Escriu aqui el teu codi */
}

int main()
{
  cout << "Introdueix la mida de la cache (bytes): ";
  cin >> mida_cache;  //2048 bytes p.e.
  cout << "Introdueix la mida de cada linia (bytes): ";
  cin >> mida_linia; // 32 bytes p.e.
  cache_lines = mida_cache/mida_linia;
  cache.resize(cache_lines);



  int hit_count, miss_count;

  init_cache();

  int M = 1024*1000;
  int i = 0;
  for (int limite = 512; limite <= 8192; limite += 512)
  {
    hit_count = miss_count = 0;
    for (int j=0; j< M; j++) { // M vale 1024*1000
      reference(i) ? ++hit_count : ++miss_count;
      i = i + mida_linia;
      if (i >= limite) i = 0;
    }
    cout << "Límit = " << limite << " " <<
    "Hits: " << hit_count << " - Miss: " << miss_count << endl;
  }

  final();

}
