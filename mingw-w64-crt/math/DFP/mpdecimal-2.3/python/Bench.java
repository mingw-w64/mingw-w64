/*
 * Copyright (c) 2008-2010 Stefan Krah. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */


import java.math.MathContext;
import java.math.BigDecimal;


public class Bench
{
    private static BigDecimal pi(MathContext mc) {
        BigDecimal lasts = new BigDecimal(0);
        BigDecimal t = new BigDecimal("3.0");
        BigDecimal s = new BigDecimal(3);
        BigDecimal n = new BigDecimal(1);
        BigDecimal na = new BigDecimal(0);
        BigDecimal d = new BigDecimal(0);
        BigDecimal da = new BigDecimal(24);

        BigDecimal eight = new BigDecimal(8);
        BigDecimal thirty_two = new BigDecimal(32);

        while (s.compareTo(lasts) != 0) {
            lasts = s;
            n = n.add(na, mc);
            na = na.add(eight, mc);
            d = d.add(da, mc);
            da = da.add(thirty_two, mc);
            t = t.multiply(n, mc);
            t = t.divide(d, mc);
            s = s.add(t, mc);
        }

        return s;
    }

    public static void main(String[] args) {
        int[] prec = {9, 19, 38, 100};
        MathContext ctx;
        BigDecimal r = new BigDecimal(0);
	long start;

	for (int p : prec) {
            ctx = new MathContext(p);
            start = System.currentTimeMillis();
            for (int i = 0; i < 10000; i++) {
                r = pi(ctx);
            }
            System.out.printf("Prec: %d\n", p);
            System.out.printf("Time: %fs\n", (System.currentTimeMillis()-start)/1000.0);
            System.out.printf("%s\n\n", r);
        }
    }
}


