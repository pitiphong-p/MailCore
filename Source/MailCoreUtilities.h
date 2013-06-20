/*
 * MailCore
 *
 * Copyright (C) 2007 - Matt Ronge
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the MailCore project nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import <libetpan/libetpan.h>

static const int MAX_PATH_SIZE = 1024;

/**
     Enables logging of all streams, data is output to standard out.
*/
void MailCoreEnableLogging();
void MailCoreDisableLogging();

NSError* MailCoreCreateErrorDetail(int errcode, NSString *description, NSString *failureReason);

NSError* MailCoreCreateError(int errcode, NSString *description);

/**
    Translates the LibEtPan IMAP error code into NSError with error description
*/
NSError* MailCoreCreateErrorFromIMAPCode(int errcode);
NSError *MailCoreCreateErrorFromIMAPError(int errcode, NSString *reason);

/**
    Translates a LibEtPan SMTP specific error code into an NSError with a description
*/
NSError* MailCoreCreateErrorFromSMTPCode(int errcode);

NSString *MailCoreDecodeMIMEPhrase(const char *data);

NSString *MailCoreGetFileNameFromMIME(struct mailmime * mime);
NSString *MailCoreGetFileNameFromMIMEFields(struct mailmime_single_fields * mime);
NSString *MailCoreGetEMLFileNameFromMIME(struct mailmime * mime);

NSDictionary * MailCoreAddressRepresentationFromMailBox(struct mailimf_mailbox *mailbox);
NSDictionary * MailCoreAddressRepresentationFromAddress(struct mailimf_address *mailbox);
NSDictionary * MailCoreAddressRepresentationFromGroup(struct mailimf_group *group);
NSArray * MailCoreAddressRepresentationArrayFromMailBoxClist(clist *list);
NSArray * MailCoreAddressRepresentationArrayFromAddressClist(clist *list);

NSArray * MailCoreStringArrayFromClist(clist *list);
clist *MailCoreClistFromStringArray(NSArray *strings);

NSDate * MailCoreDateFromMailIMAPDateTime(struct mailimf_date_time * datetime);
NSTimeZone * MailCoreTimeZoneFromDTTimeZone(int timezone);

struct mailimap_date * mailimap_dateFromDate(NSDate *date);
struct mailimap_date * mailimap_dateFromDateComponents(NSDateComponents *dateComponents);

struct mailimap_set * mailimap_setFromIndexSet(NSIndexSet *indexSet);
NSIndexSet * MailCoreIndexSetFromMailImapSet(struct mailimap_set *set);

const char * getUTF7String(NSString *str, char * buffer);

