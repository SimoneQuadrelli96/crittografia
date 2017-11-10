#include <stdio.h>
#include <gmp.h>

void fermat_factorization(){
    mpz_t n,a,b2,risultato;
    mpz_init(n);
    mpz_set_str(n,"7723537042671053533349250770213334979939936820556134073043654409875795653759249636472530580914872873851196626721386328853913207026848732669575096806570611",10);
    mpz_init(risultato);
    mpz_init(b2);
    mpz_init(a);
    mpz_sqrt(a,n);
    mpz_add(b2,a,a);
    mpz_sub(b2,b2,n);

  do{
      mpz_add_ui(a,a,1);
      mpz_mul(a,a,a);
      mpz_sub(b2,a,n);
    } while(mpz_perfect_square_p(b2) != 0);
    mpz_sqrt(risultato,b2);
    mpz_sub(risultato,a,risultato);

     gmp_printf("Ris %Zd\n\n",risultato);

     if(mpz_cmp(risultato,n) != 0)
      printf("Trovato\n");
    else
      printf("ERRORE\n");
}


void common_module_attck(){
  mpz_t n,eA,eB,d,cA,cB,r,s,k, inv_a;
  mpz_init(inv_a);
  mpz_init(k);
  mpz_init(r);
  mpz_init(s);
  mpz_init_set_str(n,"734832328116465196692838283564479145339399316070744350481249855342603693301556011015131519",10);
  mpz_init_set_str(eA,"17",10);
  mpz_init_set_str(eB,"65537",10); // (2^16)+1
  mpz_init_set_str(cA,"93734709405860059315217893988749243105435169093069740192815939750720282941641642747093171",10);
  mpz_init_set_str(cB,"269125499927676766418170761935369755935025654357890774691167668682175704132138220498309902",10);

  mpz_gcd(k,cA,n);
  mpz_gcdext(k,eA,eB,r,s);
  mpz_invert(inv_a,cA);
}


int main(int argc, char *argv[]) {
  //fermat_factorization();
  common_module_attck();
  return 0;
}
