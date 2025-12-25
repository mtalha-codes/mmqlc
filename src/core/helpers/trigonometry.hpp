#ifndef TRIGONOMETRY_HPP
#define TRIGONOMETRY_HPP
#include "boost_fwd.hpp"
#include "constants.hpp"


namespace mmqli::core::trigonometry {
    /**
     * @brief This namespace contains the definition for derived trigonometric functions and their inverses for real numbers.
     * The containing functions are inlined due to their small bodies,
     * so that the compiler won't have to spend extra time for inlining them.
     */
    namespace real {
        /**
         * @brief  This namespace currently contains angle converters aka from degrees to radians and vice versa.
         * Same here, the containing functions are inlined, to cut extra seconds for compilation.
         */
        namespace converters {
            /**
             * @brief This function converts degrees to radians.
             * @param degrees The angle in degrees.
             * @return The angle in radians
             */
            inline float1000 degrees_to_radians(const float1000 &degrees) {
                float1000 radians(constants::arbitrary_precise_pi * degrees);
                radians /= 180;
                return radians;
            }

            /**
             * @brief This function converts radians to degrees.
             * @param radians The angle in radians
             * @return The angle in degrees
             */
            inline float1000 radians_to_degrees(const float1000 &radians) {
                float1000 degrees(radians * 180);
                degrees /= constants::arbitrary_precise_pi;
                return degrees;
            }
        } // namespace converters
        /**
         * @brief This functions calculates the cotangent using the trigonometric ratio i-e cot(x) = 1/tan(x)
         * @param arg The parameter on which the operation is performed
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 cotangent(const float1000 &arg) {
            const float1000 tangent = tan(arg);
            const float1000 cotangent_result = constants::real_one / tangent;
            return cotangent_result;
        }

        /**
        * @brief This functions calculates the secant using the trigonometric ratio i-e sec(x) = 1/cos(x)
        * @param arg The parameter on which the operation is performed
        * @return The calculated result after the operation is successfully performed.
        */
        inline float1000 secant(const float1000 &arg) {
            const float1000 cosine = cos(arg);
            const float1000 secant_result = constants::real_one / cosine;
            return secant_result;
        }

        /**
        * @brief This functions calculates the cosecant using the trigonometric ratio i-e csc(x) = 1/sin(x)
        * @param arg The parameter on which the operation is performed
        * @return The calculated result after the operation is successfully performed.
        */
        inline float1000 cosecant(const float1000 &arg) {
            const float1000 sine = sin(arg);
            const float1000 cosecant_result = constants::real_one / sine;
            return cosecant_result;
        }

        /**
         * @brief This function calculates inverse cotangent by using the identity i-e acot(x) = atan(1/x)
         * @param arg The parameter on which the operation is performed.
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 inverse_cotangent(const float1000 &arg) {
            const float1000 normalized_arg(constants::real_one / arg);
            const float1000 inverse_cot = atan(normalized_arg);
            return inverse_cot;
        }

        /**
        * @brief This function calculates inverse secant by using the identity i-e asec(x) = acos(1/x)
        * @param arg The parameter on which the operation is performed.
        * @return The calculated result after the operation is successfully performed.
        */
        inline float1000 inverse_secant(const float1000 &arg) {
            const float1000 normalized_arg(constants::real_one / arg);
            const float1000 inverse_sec = acos(normalized_arg);
            return inverse_sec;
        }

        /**
         * @brief This function calculates inverse cosecant by using the identity i-e acsc(x) = asin(1/x)
         * @param arg The parameter on which the operation is performed.
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 inverse_cosecant(const float1000 &arg) {
            const float1000 normalized_arg(constants::real_one / arg);
            const float1000 inverse_cosec = asin(normalized_arg);
            return inverse_cosec;
        }

        /**
         * @brief This functions calculates the hyperbolic cotangent using the trigonometric ratio i-e coth(x) = 1/tanh(x)
         * @param arg The parameter on which the operation is performed
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 cotangent_hyperbolic(const float1000 &arg) {
            const float1000 tanh_result = tanh(arg);
            const float1000 coth = constants::real_one / tanh_result;
            return coth;
        }

        /**
         * @brief This functions calculates the hyperbolic secant using the trigonometric ratio i-e sech(x) = 1/cosh(x)
         * @param arg The parameter on which the operation is performed
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 secant_hyperbolic(const float1000 &arg) {
            const float1000 cosh_result = cosh(arg);
            const float1000 sech = constants::real_one / cosh_result;
            return sech;
        }

        /**
         * @brief This functions calculates the hyperbolic cosecant using the trigonometric ratio i-e csch(x) = 1/sinh(x)
         * @param arg The parameter on which the operation is performed
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 cosecant_hyperbolic(const float1000 &arg) {
            const float1000 sinh_result = sinh(arg);
            const float1000 csch = constants::real_one / sinh_result;
            return csch;
        }

        /**
         * @brief This function calculates the inverse hyperbolic cotangent using the identity i-e acoth(x) = atanh(1/x).
         * @param arg The parameter on which the operation is performed.
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 inverse_cotangent_hyperbolic(const float1000 &arg) {
            const float1000 normalized_arg(constants::real_one / arg);
            const float1000 acoth = atanh(normalized_arg);
            return acoth;
        }

        /**
         * @brief This function calculates the inverse hyperbolic cotangent using the identity i-e asech(x) = acosh(1/x).
         * @param arg The parameter on which the operation is performed.
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 inverse_secant_hyperbolic(const float1000 &arg) {
            const float1000 normalized_arg(constants::real_one / arg);
            const float1000 asech = acosh(normalized_arg);
            return asech;
        }

        /**
         * @brief This function calculates the inverse hyperbolic cotangent using the identity i-e acsch(x) = asinh(1/x).
         * @param arg The parameter on which the operation is performed.
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 inverse_cosecant_hyperbolic(const float1000 &arg) {
            const float1000 normalized_arg(constants::real_one / arg);
            const float1000 acsch = asinh(normalized_arg);
            return acsch;
        }
    } // namespace real

    /**
     * @brief This namespace contains the definition for derived trigonometric functions and their inverses for complex numbers.
     * The containing functions are inlined due to their small bodies,
     * so that the compiler won't have to spend extra time for inlining them.
     */
    namespace complex {
        inline complex1000 cot(const complex1000 &arg) {
            const complex1000 tang = std::tan(arg);
            complex1000 coT = constants::complex_one / tang;
            return coT;
        }

        inline complex1000 sec(const complex1000 &arg) {
            const complex1000 COS = std::cos(arg);
            const
                    complex1000 SEC = constants::complex_one / COS;
            return SEC;
        }

        inline complex1000 csc(const complex1000 &arg) {
            const complex1000 SIN = std::sin(arg);
            complex1000 CSC = constants::complex_one / SIN;
            return CSC;
        }

        inline complex1000 acot(const complex1000 &arg) {
            const complex1000 suitable_arg(constants::complex_one / arg);
            complex1000 acotngt = std::atan(suitable_arg);
            return acotngt;
        }

        inline complex1000 asec(const complex1000 &arg) {
            const complex1000 suitable_arg(constants::complex_one / arg);
            complex1000 asecnt = std::acos(suitable_arg);
            return asecnt;
        }


        inline complex1000 acsc(const complex1000 &arg) {
            const complex1000 suitable_arg(constants::complex_one / arg);
            complex1000 cscnt = std::asin(suitable_arg);
            return cscnt;
        }

        inline complex1000 coth(const complex1000 &arg) {
            const complex1000 tangh = std::tanh(arg);
            complex1000 coTh = constants::complex_one / tangh;
            return coTh;
        }

        inline complex1000 sech(const complex1000 &arg) {
            const complex1000 COSh = std::cosh(arg);
            complex1000 SECh = constants::complex_one / COSh;
            return SECh;
        }

        inline complex1000 csch(const complex1000 &arg) {
            const complex1000 SINh = std::sinh(arg);
            complex1000 CSCh = constants::complex_one / SINh;
            return CSCh;
        }

        inline complex1000 acoth(const complex1000 &arg) {
            const complex1000 suitable_arg(constants::complex_one / arg);
            complex1000 acotngth = std::atanh(suitable_arg);
            return acotngth;
        }

        inline complex1000 asech(const complex1000 &arg) {
            const complex1000 suitable_arg(constants::complex_one / arg);
            complex1000 asecnth = std::acosh(suitable_arg);
            return asecnth;
        }

        inline complex1000 acsch(const complex1000 &arg) {
            const complex1000 suitable_arg(constants::complex_one / arg);
            complex1000 cscnth = std::asinh(suitable_arg);
            return cscnth;
        }
    } // namespace complex
} //namespace mmqli::core::trigonometry
#endif // TRIGONOMETRY_HPP
