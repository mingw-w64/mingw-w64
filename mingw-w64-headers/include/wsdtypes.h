/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WSDTYPES
#define _INC_WSDTYPES

#ifndef _INC_WSDAPI
#error Please include wsdapi.h instead of this header. This header cannot be used directly.
#endif

#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _WSD_PROTOCOL_TYPE {
  WSD_PT_NONE    = 0x00,
  WSD_PT_UDP     = 0x01,
  WSD_PT_HTTP    = 0x02,
  WSD_PT_HTTPS   = 0x04,
  WSD_PT_ALL     = 0xff 
} WSD_PROTOCOL_TYPE;

typedef enum _WSDEventType {
  WSDET_NONE                   = 0,
  WSDET_INCOMING_MESSAGE       = 1,
  WSDET_INCOMING_FAULT         = 2,
  WSDET_TRANSMISSION_FAILURE   = 3,
  WSDET_RESPONSE_TIMEOUT       = 4 
} WSDEventType;

typedef HRESULT ( *PWSD_SOAP_MESSAGE_HANDLER )(
    IUnknown *thisUnknown,
    WSD_EVENT *event
);

typedef HRESULT ( *WSD_STUB_FUNCTION )(
    IUnknown *server,
    IWSDServiceMessaging *session,
    WSD_EVENT *event
);

typedef struct _WSD_HANDLER_CONTEXT {
  PWSD_SOAP_MESSAGE_HANDLER Handler;
  void                      *PVoid;
  IUnknown                  *Unknown;
} WSD_HANDLER_CONTEXT;

typedef struct _WSD_REFERENCE_PROPERTIES {
  WSDXML_ELEMENT *Any;
} WSD_REFERENCE_PROPERTIES;

typedef struct _WSD_REFERENCE_PARAMETERS {
  WSDXML_ELEMENT *Any;
} WSD_REFERENCE_PARAMETERS;

typedef struct _WSD_ENDPOINT_REFERENCE {
  const WCHAR              *Address;
  WSD_REFERENCE_PROPERTIES ReferenceProperties;
  WSD_REFERENCE_PARAMETERS ReferenceParameters;
  WSDXML_NAME              *PortType;
  WSDXML_NAME              *ServiceName;
  WSDXML_ELEMENT           *Any;
} WSD_ENDPOINT_REFERENCE;

typedef struct _WSD_APP_SEQUENCE {
  ULONGLONG   InstanceId;
  const WCHAR *SequenceId;
  ULONGLONG   MessageNumber;
} WSD_APP_SEQUENCE;

typedef struct _WSD_HEADER_RELATESTO {
  WSDXML_NAME *RelationshipType;
  const WCHAR *MessageID;
} WSD_HEADER_RELATESTO;

typedef struct _WSD_SOAP_HEADER {
  const WCHAR            *To;
  const WCHAR            *Action;
  const WCHAR            *MessageID;
  WSD_HEADER_RELATESTO   RelatesTo;
  WSD_ENDPOINT_REFERENCE *ReplyTo;
  WSD_ENDPOINT_REFERENCE *From;
  WSD_ENDPOINT_REFERENCE *FaultTo;
  WSD_APP_SEQUENCE       *AppSequence;
  WSDXML_ELEMENT         *AnyHeaders;
} WSD_SOAP_HEADER;

typedef struct _WSD_SOAP_MESSAGE {
  WSD_SOAP_HEADER Header;
  void            *Body;
  WSDXML_TYPE     *BodyType;
} WSD_SOAP_MESSAGE;

typedef struct _WSD_OPERATION {
  WSDXML_TYPE       *RequestType;
  WSDXML_TYPE       *ResponseType;
  WSD_STUB_FUNCTION RequestStubFunction;
} WSD_OPERATION;

typedef struct _WSD_EVENT {
  HRESULT               Hr;
  DWORD                 EventType;
  WCHAR                 *DispatchTag;
  WSD_HANDLER_CONTEXT   HandlerContext;
  WSD_SOAP_MESSAGE      *Soap;
  WSD_OPERATION         *Operation;
  IWSDMessageParameters *MessageParameters;
} WSD_EVENT;

typedef struct _WSD_SOAP_FAULT_SUBCODE {
  WSDXML_NAME            *Value;
  WSD_SOAP_FAULT_SUBCODE *Subcode;
} WSD_SOAP_FAULT_SUBCODE;

typedef struct _WSD_SOAP_FAULT_CODE {
  WSDXML_NAME            *Value;
  WSD_SOAP_FAULT_SUBCODE *Subcode;
} WSD_SOAP_FAULT_CODE;

typedef struct _WSD_LOCALIZED_STRING {
  const WCHAR *lang;
  const WCHAR *String;
} WSD_LOCALIZED_STRING;

typedef struct _WSD_LOCALIZED_STRING_LIST {
  WSD_LOCALIZED_STRING_LIST *Next;
  WSD_LOCALIZED_STRING      *Element;
} WSD_LOCALIZED_STRING_LIST;

typedef struct _WSD_SOAP_FAULT_REASON {
  WSD_LOCALIZED_STRING_LIST *Text;
} WSD_SOAP_FAULT_REASON;

typedef struct _WSD_SOAP_FAULT {
  WSD_SOAP_FAULT_CODE   *Code;
  WSD_SOAP_FAULT_REASON *Reason;
  const WCHAR           *Node;
  const WCHAR           *Role;
  WSDXML_ELEMENT        *Detail;
} WSD_SOAP_FAULT;

typedef struct _REQUESTBODY_GetStatus {
  WSDXML_ELEMENT *Any;
} REQUESTBODY_GetStatus;

typedef struct _WSD_DURATION {
  WINBOOL isPositive;
  ULONG year;
  ULONG month;
  ULONG day;
  ULONG hour;
  ULONG minute;
  ULONG second;
  ULONG millisecond;
} WSD_DURATION;

typedef struct _WSD_DATETIME {
  WINBOOL isPositive;
  ULONG year;
  UCHAR month;
  UCHAR day;
  UCHAR hour;
  UCHAR minute;
  UCHAR second;
  UINT  millisecond;
  WINBOOL TZIsLocal;
  WINBOOL TZIsPositive;
  UCHAR TZHour;
  UCHAR TZMinute;
} WSD_DATETIME;

typedef struct _WSD_EVENTING_EXPIRES {
  WSD_DURATION *Duration;
  WSD_DATETIME *DateTime;
} WSD_EVENTING_EXPIRES;

typedef struct _REQUESTBODY_Renew {
  WSD_EVENTING_EXPIRES *Expires;
  WSDXML_ELEMENT       *Any;
} REQUESTBODY_Renew;

typedef struct _WSD_EVENTING_DELIVERY_MODE {
  const WCHAR *Mode;
  void        *Data;
} WSD_EVENTING_DELIVERY_MODE;

typedef struct _WSD_EVENTING_FILTER {
  const WCHAR *Dialect;
  void        *Data;
} WSD_EVENTING_FILTER;

typedef struct _REQUESTBODY_Subscribe {
  WSD_ENDPOINT_REFERENCE     *EndTo;
  WSD_EVENTING_DELIVERY_MODE *Delivery;
  WSD_EVENTING_EXPIRES       *Expires;
  WSD_EVENTING_FILTER        *Filter;
  WSDXML_ELEMENT             *Any;
} REQUESTBODY_Subscribe;

typedef struct _REQUESTBODY_Unsubscribe {
  WSDXML_ELEMENT *any;
} REQUESTBODY_Unsubscribe;

typedef struct _WSD_METADATA_SECTION_LIST {
  WSD_METADATA_SECTION_LIST *Next;
  WSD_METADATA_SECTION      *Element;
} WSD_METADATA_SECTION_LIST;

typedef struct _RESPONSEBODY_GetMetadata {
  WSD_METADATA_SECTION_LIST *Metadata;
} RESPONSEBODY_GetMetadata;

typedef struct _RESPONSEBODY_GetStatus {
  WSD_EVENTING_EXPIRES *expires;
  WSDXML_ELEMENT       *any;
} RESPONSEBODY_GetStatus;

typedef struct _RESPONSEBODY_Renew {
  WSD_EVENTING_EXPIRES *expires;
  WSDXML_ELEMENT       *Any;
} RESPONSEBODY_Renew;

typedef struct _RESPONSEBODY_Subscribe {
  WSD_ENDPOINT_REFERENCE *SubscriptionManager;
  WSD_EVENTING_EXPIRES   *expires;
  WSDXML_ELEMENT         *Any;
} RESPONSEBODY_Subscribe;

typedef struct _RESPONSEBODY_SubscriptionEnd {
  WSD_ENDPOINT_REFERENCE *SubscriptionManager;
  const WCHAR            *Status;
  WSD_LOCALIZED_STRING   *Reason;
  WSDXML_ELEMENT         *Any;
} RESPONSEBODY_SubscriptionEnd;

typedef struct _WSD_BYE {
  WSD_ENDPOINT_REFERENCE *EndpointReference;
  WSDXML_ELEMENT         *Any;
} WSD_BYE;

typedef struct _WSD_ENDPOINT_REFERENCE_LIST {
  WSD_ENDPOINT_REFERENCE_LIST *Next;
  WSD_ENDPOINT_REFERENCE      *Element;
} WSD_ENDPOINT_REFERENCE_LIST;

typedef struct _WSD_EVENTING_DELIVERY_MODE_PUSH {
  WSD_ENDPOINT_REFERENCE *NotifyTo;
} WSD_EVENTING_DELIVERY_MODE_PUSH;

typedef struct _WSD_URI_LIST {
  WSD_URI_LIST *Next;
  const WCHAR  *Element;
} WSD_URI_LIST;

typedef struct _WSD_EVENTING_FILTER_ACTION {
  WSD_URI_LIST *Actions;
} WSD_EVENTING_FILTER_ACTION;

typedef struct _WSD_NAME_LIST {
  WSD_NAME_LIST *Next;
  WSDXML_NAME   *Element;
} WSD_NAME_LIST;

typedef struct _WSD_SCOPES {
  const WCHAR  *MatchBy;
  WSD_URI_LIST *Scopes;
} WSD_SCOPES;

typedef struct _WSD_HELLO {
  WSD_ENDPOINT_REFERENCE *EndpointReference;
  WSD_NAME_LIST          *Types;
  WSD_SCOPES             *Scopes;
  WSD_URI_LIST           *XAddrs;
  ULONGLONG              MetadataVersion;
  WSDXML_ELEMENT         *Any;
} WSD_HELLO;

typedef struct _WSD_SERVICE_METADATA {
  WSD_ENDPOINT_REFERENCE_LIST *EndpointReference;
  WSD_NAME_LIST               *Types;
  const WCHAR                 *ServiceId;
  WSDXML_ELEMENT              *Any;
} WSD_SERVICE_METADATA;

typedef struct _WSD_SERVICE_METADATA_LIST {
  WSD_SERVICE_METADATA_LIST *Next;
  WSD_SERVICE_METADATA      *Element;
} WSD_SERVICE_METADATA_LIST;

typedef struct _WSD_HOST_METADATA {
  WSD_SERVICE_METADATA      *Host;
  WSD_SERVICE_METADATA_LIST *Hosted;
} WSD_HOST_METADATA;

typedef struct _WSD_METADATA_SECTION {
  const WCHAR            *Dialect;
  const WCHAR            *Identifier;
  void                   *Data;
  WSD_ENDPOINT_REFERENCE *MetadataReference;
  const WCHAR            *Location;
  WSDXML_ELEMENT         *Any;
} WSD_METADATA_SECTION;

typedef struct _WSD_PORT_TYPE {
  DWORD             EncodedName;
  DWORD             OperationCount;
  WSD_OPERATION     *Operations;
  WSD_PROTOCOL_TYPE ProtocolType;
} WSD_PORT_TYPE;

typedef struct _WSD_PROBE {
  WSD_NAME_LIST  *Types;
  WSD_SCOPES     *Scopes;
  WSDXML_ELEMENT *Any;
} WSD_PROBE;

typedef struct _WSD_PROBE_MATCH {
  WSD_ENDPOINT_REFERENCE *EndpointReference;
  WSD_NAME_LIST          *Types;
  WSD_SCOPES             *Scopes;
  WSD_URI_LIST           *XAddrs;
  ULONGLONG              MetadataVersion;
  WSDXML_ELEMENT         *Any;
} WSD_PROBE_MATCH;

typedef struct _WSD_PROBE_MATCH_LIST {
  WSD_PROBE_MATCH_LIST *Next;
  WSD_PROBE_MATCH      *Element;
} WSD_PROBE_MATCH_LIST;

typedef struct _WSD_PROBE_MATCHES {
  WSD_PROBE_MATCH_LIST *ProbeMatch;
  WSDXML_ELEMENT       *Any;
} WSD_PROBE_MATCHES;

typedef struct _WSD_RELATIONSHIP_METADATA {
  const WCHAR       *Type;
  WSD_HOST_METADATA *Data;
  WSDXML_ELEMENT    *Any;
} WSD_RELATIONSHIP_METADATA;

typedef struct _WSD_RESOLVE {
  WSD_ENDPOINT_REFERENCE *EndpointReference;
  WSDXML_ELEMENT         *Any;
} WSD_RESOLVE;

typedef struct _WSD_RESOLVE_MATCH {
  WSD_ENDPOINT_REFERENCE *EndpointReference;
  WSD_NAME_LIST          *Types;
  WSD_SCOPES             *Scopes;
  WSD_URI_LIST           *XAddrs;
  ULONGLONG              MetadataVersion;
  WSDXML_ELEMENT         *Any;
} WSD_RESOLVE_MATCH;

typedef struct _WSD_RESOLVE_MATCHES {
  WSD_RESOLVE_MATCH *ResolveMatch;
  WSDXML_ELEMENT    *Any;
} WSD_RESOLVE_MATCHES;

typedef struct _WSD_SYNCHRONOUS_RESPONSE_CONTEXT {
  HRESULT               hr;
  HANDLE                eventHandle;
  IWSDMessageParameters *messageParameters;
  void                  *results;
} WSD_SYNCHRONOUS_RESPONSE_CONTEXT;

typedef struct _WSD_THIS_DEVICE_METADATA {
  WSD_LOCALIZED_STRING_LIST *FriendlyName;
  const WCHAR               *FirmwareVersion;
  const WCHAR               *SerialNumber;
  WSDXML_ELEMENT            *Any;
} WSD_THIS_DEVICE_METADATA;

typedef struct _WSD_THIS_MODEL_METADATA {
  WSD_LOCALIZED_STRING_LIST *Manufacturer;
  const WCHAR               *ManufacturerUrl;
  WSD_LOCALIZED_STRING_LIST *ModelName;
  const WCHAR               *ModelNumber;
  const WCHAR               *ModelUrl;
  const WCHAR               *PresentationUrl;
  WSDXML_ELEMENT            *Any;
} WSD_THIS_MODEL_METADATA;

typedef struct _WSD_UNKNOWN_LOOKUP {
  WSDXML_ELEMENT *Any;
} WSD_UNKNOWN_LOOKUP;

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_WSDTYPES*/
