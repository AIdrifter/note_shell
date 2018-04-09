#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

//This:
//
//static bool rate_control_cap_mask(struct ieee80211_sub_if_data *sdata,
//                                   struct ieee80211_supported_band *sband,
//                                   struct ieee80211_sta *sta, u32 *mask,
//                                   u8 mcs_mask[IEEE80211_HT_MCS_MASK_LEN])
//is horribly broken to begin with, because array arguments in C don’t actually exist. Sadly, compilers accept it for various bad historical reasons, and silently turn it into just a pointer argument. There are arguments for them, but they are from weak minds.
//
int linus_angry(char A[100], char *ptr)
{
    printf(" function parameter sizeof(A): %u  == sizeof (ptr) %u", sizeof(A), sizeof(ptr) );
}

int main()
{
    bool bool_va  = true;
    uint32_t uint32_va = INT_MAX;
    char array[50] = {0};
    linus_angry(array, array);
    return 0;
}
