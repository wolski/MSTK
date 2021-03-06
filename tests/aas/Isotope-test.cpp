/*
 * Isotope-test.cpp
 *
 * Copyright (c) 2011 Mathias Wilhelm
 * Copyright (c) 2011 Marc Kirchner
 *
 * This file is part of the Mass Spectrometry Toolkit (MSTK).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <MSTK/aas/Isotope.hpp>

#include "unittest.hxx"

#include <iostream>

using namespace mstk;
using namespace aas::elements;

/** Short description.
 * Long description.
 */
struct IsotopeTestSuite : vigra::test_suite
{
    /** Constructor.
     * The IsotopeTestSuite constructor adds all Isotope tests to
     * the test suite. If you write an additional test, add the test
     * case here.
     */
    IsotopeTestSuite() :
            vigra::test_suite("Isotope")
    {
        add(testCase(&IsotopeTestSuite::testIsotope));
    }

    void testIsotope()
    {
        double mass = 101.1;
        double frequency = 0.99;
        Isotope i1(mass, frequency);
        Isotope i2(12.4, 0.32);
        i2 = i1;
        Isotope i3(mass + 1, frequency);

        shouldEqual(i1.getMass(), mass);
        shouldEqual(i1.getFrequency(), frequency);
        shouldEqual(i1, i2);
        shouldEqual(i1 == i3, false);
        shouldEqual(i1 != i3, true);
    }

};

/** The main function that runs the tests for class Isotope.
 * Under normal circumstances you need not edit this.
 */
int main()
{
    IsotopeTestSuite test;
    int success = test.run();
    std::cout << test.report() << std::endl;
    return success;
}

