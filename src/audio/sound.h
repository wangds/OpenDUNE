/** @file src/audio/sound.h Sound definitions. */

#ifndef SOUND_H
#define SOUND_H

/** Information about sound files. */
typedef struct SoundData {
	const char *string; /*!< Pointer to a string. */
	uint16 variable_04; /*!< ?? */
} SoundData;

/** Maximal number of spoken audio fragments in one message. */
#define NUM_SPEECH_PARTS 5

/** Audio and visual feedback about events and commands. */
typedef struct Feedback {
	uint16 voiceId[NUM_SPEECH_PARTS]; /*!< English spoken text. */
	uint16 messageId;                 /*!< Message to display in the viewport when audio is disabled. */
	uint16 soundId;                   /*!< Sound. */
} Feedback;

/** Number of voices in the game. */
#define NUM_VOICES 131

extern const uint16 g_table_voiceMapping[120];
extern const SoundData g_table_musics[38];
extern const SoundData g_table_voices[NUM_VOICES];
extern const Feedback g_feedback[94];
extern const uint16 g_translatedVoice[94][NUM_SPEECH_PARTS];

extern void Music_Play(uint16 musicID);
extern void Voice_PlayAtTile(int16 voiceID, tile32 position);
extern void Voice_Play(int16 voiceID);
extern void Voice_LoadVoices(uint16 voiceSet);
extern void Voice_UnloadVoices(void);

extern void Sound_StartSound(uint16 index);
extern void Sound_Output_Feedback(uint16 index);
extern bool Sound_StartSpeech(void);
extern void *Sound_Unknown0823(const char *filename, uint32 *retFileSize);

#endif /* SOUND_H */
