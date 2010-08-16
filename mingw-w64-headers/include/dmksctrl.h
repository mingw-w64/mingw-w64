/*
 * dmksctrl.h
 *
 * Contributors:
 *   Created by Johannes Anderwald
 *
 * THIS SOFTWARE IS NOT COPYRIGHTED
 *
 * This source code is offered for use in the public domain. You may
 * use, modify or distribute it freely.
 *
 * This code is distributed in the hope that it will be useful but
 * WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 * DISCLAIMED. This includes but is not limited to warranties of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#ifndef _IKsControl_
#define _IKsControl_

#undef INTERFACE
#define INTERFACE IKsControl
DECLARE_INTERFACE_(IKsControl, IUnknown)
{
     /* IUnknown */
    STDMETHOD(QueryInterface)       (THIS_ REFIID, LPVOID FAR *) PURE;
    STDMETHOD_(ULONG,AddRef)        (THIS) PURE;
    STDMETHOD_(ULONG,Release)       (THIS) PURE;

    /*IKsControl*/
    STDMETHOD(KsProperty)(
        THIS_
        PKSPROPERTY Property,
        ULONG PropertyLength,
        LPVOID PropertyData,
        ULONG DataLength,
        ULONG* BytesReturned
    ) PURE;
    STDMETHOD(KsMethod)(
        THIS_
        PKSMETHOD Method,
        ULONG MethodLength,
        LPVOID MethodData,
        ULONG DataLength,
        ULONG* BytesReturned
    ) PURE;
    STDMETHOD(KsEvent)(
        THIS_
        PKSEVENT Event,
        ULONG EventLength,
        LPVOID EventData,
        ULONG DataLength,
        ULONG* BytesReturned
    ) PURE;
};

#endif /* _IKsControl_ */

