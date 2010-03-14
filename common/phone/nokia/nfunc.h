
#ifndef phone_nokia_h
#define phone_nokia_h

#include "ncommon.h"
#include "../../gsmcomon.h"
#include "../../gsmstate.h"

extern unsigned char N71_65_MEMORY_TYPES[];
extern GSM_Profile_PhoneTableValue Profile71_65[];

GSM_Error NOKIA_ReplyGetPhoneString		(GSM_Protocol_Message msg, GSM_StateMachine *s);
GSM_Error N71_65_ReplyGetMemoryError		(unsigned char error     , GSM_StateMachine *s);
GSM_Error N71_65_ReplyWritePhonebook		(GSM_Protocol_Message msg, GSM_StateMachine *s);
GSM_Error N71_65_ReplyGetCalendarInfo		(GSM_Protocol_Message msg, GSM_StateMachine *s, GSM_NOKIACalendarLocations *LastCalendar);
GSM_Error N71_65_ReplyGetNextCalendar1		(GSM_Protocol_Message msg, GSM_StateMachine *s);
GSM_Error N71_65_ReplyGetNextCalendar2		(GSM_Protocol_Message msg, GSM_StateMachine *s);
GSM_Error N71_65_ReplyAddCalendar1		(GSM_Protocol_Message msg, GSM_StateMachine *s);
GSM_Error N71_65_ReplyAddCalendar2		(GSM_Protocol_Message msg, GSM_StateMachine *s);
GSM_Error N71_65_ReplyDelCalendar		(GSM_Protocol_Message msg, GSM_StateMachine *s);
GSM_Error N71_65_ReplyGetCalendarNotePos	(GSM_Protocol_Message msg, GSM_StateMachine *s,int *FirstCalendarPos);
GSM_Error N71_65_ReplyDeleteMemory		(GSM_Protocol_Message msg, GSM_StateMachine *s);
GSM_Error N71_65_ReplyCallInfo			(GSM_Protocol_Message msg, GSM_StateMachine *s);
GSM_Error N71_65_ReplyUSSDInfo			(GSM_Protocol_Message msg, GSM_StateMachine *s);
GSM_Error DCT3DCT4_ReplyGetWAPBookmark		(GSM_Protocol_Message msg, GSM_StateMachine *s, bool FullLength);
GSM_Error DCT3DCT4_ReplySetWAPBookmark		(GSM_Protocol_Message msg, GSM_StateMachine *s);
GSM_Error DCT3DCT4_ReplyDelWAPBookmark		(GSM_Protocol_Message msg, GSM_StateMachine *s);
GSM_Error DCT3DCT4_ReplyEnableWAP		(GSM_Protocol_Message msg, GSM_StateMachine *s);
GSM_Error DCT3DCT4_ReplyGetModelFirmware	(GSM_Protocol_Message msg, GSM_StateMachine *s);
GSM_Error N71_65_ReplySendDTMF			(GSM_Protocol_Message msg, GSM_StateMachine *s);
  
GSM_Error NOKIA_GetManufacturer			(GSM_StateMachine *s);
GSM_Error NOKIA_GetPhoneString			(GSM_StateMachine *s, unsigned char *msgframe, int msglen, unsigned char msgtype, char *retvalue, GSM_Phone_RequestID request, int startresponse);
GSM_Error NOKIA_SetIncomingSMS			(GSM_StateMachine *s, bool enable);
GSM_Error NOKIA_SetIncomingCall			(GSM_StateMachine *s, bool enable);
GSM_Error NOKIA_SetIncomingUSSD			(GSM_StateMachine *s, bool enable);
GSM_Error N71_65_EnableFunctions		(GSM_StateMachine *s, char *buff,int len);
GSM_Error N71_65_GetNextCalendar1		(GSM_StateMachine *s, GSM_CalendarEntry *Note, bool start, GSM_NOKIACalendarLocations *LastCalendar, int *LastCalendarYear, int *LastCalendarPos);
GSM_Error N71_65_GetNextCalendar2		(GSM_StateMachine *s, GSM_CalendarEntry *Note, bool start, int *LastCalendarYear, int *LastCalendarPos);
GSM_Error N71_65_DelCalendar			(GSM_StateMachine *s, GSM_CalendarEntry *Note);
GSM_Error N71_65_AddCalendar1			(GSM_StateMachine *s, GSM_CalendarEntry *Note, int *FirstCalendarPos, bool Past);
GSM_Error N71_65_AddCalendar2			(GSM_StateMachine *s, GSM_CalendarEntry *Note, bool Past);
GSM_Error N71_65_DeleteMemory			(GSM_StateMachine *s, GSM_PhonebookEntry *entry, unsigned char *memory);
GSM_Error DCT3DCT4_SendDTMF			(GSM_StateMachine *s, char *sequence);
GSM_Error DCT3DCT4_DeleteWAPBookmark		(GSM_StateMachine *s, GSM_WAPBookmark 	  *bookmark);
GSM_Error DCT3DCT4_EnableWAP			(GSM_StateMachine *s);
GSM_Error DCT3DCT4_GetModel			(GSM_StateMachine *s);
GSM_Error DCT3DCT4_GetFirmware			(GSM_StateMachine *s);
GSM_Error DCT3DCT4_GetWAPBookmark		(GSM_StateMachine *s, GSM_WAPBookmark	  *bookmark	);

int 		NOKIA_SetUnicodeString		(GSM_StateMachine *s, unsigned char *dest, unsigned char *string, bool FullLength);
void 		NOKIA_GetUnicodeString		(GSM_StateMachine *s, int *current, unsigned char *input, unsigned char *output, bool FullLength);
GSM_MemoryType 	NOKIA_GetMemoryType 		(GSM_StateMachine *s, GSM_MemoryType memory_type, unsigned char *ID);
void 		NOKIA_DecodeSMSState		(GSM_StateMachine *s, unsigned char state, GSM_SMSMessage *sms);
void		NOKIA_EncodeDateTime		(GSM_StateMachine *s, unsigned char* buffer, GSM_DateTime *datetime);
void		NOKIA_DecodeDateTime		(GSM_StateMachine *s, unsigned char* buffer, GSM_DateTime *datetime);
void 		NOKIA_SortSMSFolderStatus	(GSM_StateMachine *s, GSM_NOKIASMSFolder *Folder);
void 		NOKIA_GetDefaultCallerGroupName	(GSM_StateMachine *s, GSM_Bitmap *Bitmap);
void 		NOKIA_GetDefaultProfileName	(GSM_StateMachine *s, GSM_Profile *Profile);
void NOKIA_FindFeatureValue(GSM_StateMachine		*s,
			    GSM_Profile_PhoneTableValue ProfileTable[],
  			    unsigned char 		ID,
  			    unsigned char 		Value,
  			    GSM_Phone_Data 		*Data,
  			    bool			CallerGroups);
bool NOKIA_FindPhoneFeatureValue(GSM_StateMachine		*s,
				 GSM_Profile_PhoneTableValue 	ProfileTable[],
  				 GSM_Profile_Feat_ID		FeatureID,
  				 GSM_Profile_Feat_Value		FeatureValue,
  			    	 unsigned char 			*PhoneID,
  			    	 unsigned char 			*PhoneValue);
  
GSM_Error N71_65_DecodePhonebook		(GSM_StateMachine	*s,
						 GSM_PhonebookEntry 	*entry,
  				 		 GSM_Bitmap 		*bitmap,
  				 		 GSM_SpeedDial 		*speed,
  				 		 unsigned char 		*MessageBuffer,
  				 		 int 			MessageLength);
int 		N71_65_EncodePhonebookFrame	(GSM_StateMachine *s, unsigned char *req, GSM_PhonebookEntry entry, int *block2, bool DCT4);
int 		N71_65_PackPBKBlock		(GSM_StateMachine *s, int id, int size, int no, unsigned char *buf, unsigned char *block);

#endif

/* How should editor hadle tabs in this file? Add editor commands here.
 * vim: noexpandtab sw=8 ts=8 sts=8:
 */
