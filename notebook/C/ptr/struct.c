#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct __tagDRM_TEE_POLICY_RESTRICTION
{
    /*
    ** XMR_OBJECT_TYPE_EXPLICIT_ANALOG_VIDEO_OUTPUT_PROTECTION_CONTAINER
    ** XMR_OBJECT_TYPE_EXPLICIT_DIGITAL_AUDIO_OUTPUT_PROTECTION_CONTAINER
    ** XMR_OBJECT_TYPE_EXPLICIT_DIGITAL_VIDEO_OUTPUT_PROTECTION_CONTAINER
    */
    int   wRestrictionCategory;

    int     idRestrictionType;

    int  cbRestrictionConfiguration;
    char  *pbRestrictionConfiguration;
} DRM_TEE_POLICY_RESTRICTION;



typedef struct __tagDRM_TEE_POLICY_INFO
{
    int                   dwDecryptionMode;                                       /* One of the values from the OEM_TEE_AES128CTR_DECRYPTION_MODE enum */
    int                    wSecurityLevel;
    bool                    fRealTimeExpirationPresent;
    int                   dwPlayEnablers;                                         /* Bitmask of values from the DRM_TEE_PLAY_ENABLER_TYPE enum */
    int                   cRestrictions;
    DRM_TEE_POLICY_RESTRICTION *pRestrictions;                                          /* Array of size cRestrictions */
} DRM_TEE_POLICY_INFO;


int main()
{
   DRM_TEE_POLICY_INFO *ptr = malloc(sizeof(DRM_TEE_POLICY_RESTRICTION));
   ptr->cRestrictions = 3;
   ptr->pRestrictions = malloc(sizeof(DRM_TEE_POLICY_RESTRICTION)*ptr->cRestrictions);
   ptr->pRestrictions[0].wRestrictionCategory = 1;
   // ptr->pRestrictions[0]->wRestrictionCategory = 2; // check dereference meaning
   ptr->pRestrictions[1].wRestrictionCategory = 3;
   ptr->pRestrictions[2].wRestrictionCategory = 4;
}
