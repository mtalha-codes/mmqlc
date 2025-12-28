#ifndef TRIGONOMETRY_HPP
#define TRIGONOMETRY_HPP
#include "boost_fwd.hpp"
#include "constants.hpp"

namespace mmqli::core::trigonometry {
    /**
     * @brief This namespace contains the definition for derived trigonometric
     * functions and their inverses for real numbers. The containing functions are
     * inlined due to their small bodies, so that the compiler won't have to spend
     * extra time for inlining them.
     */
    namespace real {
        /**
         * @brief  This namespace currently contains angle converters aka from degrees
         * to radians and vice versa. Same here, the containing functions are inlined,
         * to cut extra seconds for compilation.
         */
        namespace converters {
            /**
             * @brief This function converts degrees to radians.
             * @param degrees The angle in degrees.
             * @return The angle in radians
             */
            inline float1000 degrees_to_radians(const float1000& degrees) {
                float1000 radians{ constants::arbitrary_precise_pi * degrees };
                radians /= 180;
                return radians;
            }

            /**
             * @brief This function converts radians to degrees.
             * @param radians The angle in radians
             * @return The angle in degrees
             */
            inline float1000 radians_to_degrees(const float1000& radians) {
                float1000 degrees{ radians * 180 };
                degrees /= constants::arbitrary_precise_pi;
                return degrees;
            }
        } // namespace converters

        /**
         * @brief This functions calculates the cotangent using the trigonometric ratio
         * i-e cot(x) = 1/tan(x)
         * @param arg The parameter on which the operation is performed
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 cotangent(const float1000& arg) {
            const float1000 tangent { tan(arg) };
            const float1000 cotangent_result { constants::real_one / tangent };
            return cotangent_result;
        }

        /**
         * @brief This functions calculates the secant using the trigonometric ratio i-e
         * sec(x) = 1/cos(x)
         * @param arg The parameter on which the operation is performed
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 secant(const float1000& arg) {
            const float1000 cosine { cos(arg) };
            const float1000 secant_result{ constants::real_one / cosine };
            return secant_result;
        }

        /**
         * @brief This functions calculates the cosecant using the trigonometric ratio
         * i-e csc(x) = 1/sin(x)
         * @param arg The parameter on which the operation is performed
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 cosecant(const float1000& arg) {
            const float1000 sine{ sin(arg) };
            const float1000 cosecant_result{ constants::real_one / sine };
            return cosecant_result;
        }

        /**
         * @brief This function calculates inverse cotangent by using the identity i-e
         * acot(x) = atan(1/x)
         * @param arg The parameter on which the operation is performed.
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 inverse_cotangent(const float1000& arg) {
            const float1000 normalized_arg{ constants::real_one / arg };
            const float1000 inverse_cot{ atan(normalized_arg) };
            return inverse_cot;
        }

        /**
         * @brief This function calculates inverse secant by using the identity i-e
         * asec(x) = acos(1/x)
         * @param arg The parameter on which the operation is performed.
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 inverse_secant(const float1000& arg) {
            const float1000 normalized_arg{constants::real_one / arg};
            const float1000 inverse_sec { acos(normalized_arg)};
            return inverse_sec;
        }

        /**
         * @brief This function calculates inverse cosecant by using the identity i-e
         * acsc(x) = asin(1/x)
         * @param arg The parameter on which the operation is performed.
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 inverse_cosecant(const float1000& arg) {
            const float1000 normalized_arg{constants::real_one / arg};
            const float1000 inverse_cosec { asin(normalized_arg)};
            return inverse_cosec;
        }

        /**
         * @brief This functions calculates the hyperbolic cotangent using the
         * trigonometric ratio i-e coth(x) = 1/tanh(x)
         * @param arg The parameter on which the operation is performed
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 cotangent_hyperbolic(const float1000& arg) {
            const float1000 tanh_result { tanh(arg)};
            const float1000 coth { constants::real_one / tanh_result};
            return coth;
        }

        /**
         * @brief This functions calculates the hyperbolic secant using the
         * trigonometric ratio i-e sech(x) = 1/cosh(x)
         * @param arg The parameter on which the operation is performed
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 secant_hyperbolic(const float1000& arg) {
            const float1000 cosh_result { cosh(arg)};
            const float1000 sech { constants::real_one / cosh_result};
            return sech;
        }

        /**
         * @brief This functions calculates the hyperbolic cosecant using the
         * trigonometric ratio i-e csch(x) = 1/sinh(x)
         * @param arg The parameter on which the operation is performed
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 cosecant_hyperbolic(const float1000& arg) {
            const float1000 sinh_result { sinh(arg)};
            const float1000 csch { constants::real_one / sinh_result };
            return csch;
        }
        /**
         * @brief This function calculates the inverse hyperbolic cotangent using the
         * identity i-e acoth(x) = atanh(1/x).
         * @param arg The parameter on which the operation is performed.
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 inverse_cotangent_hyperbolic(const float1000& arg) {
            const float1000 normalized_argument{constants::real_one / arg};
            const float1000 acoth { atanh(normalized_argument)};
            return acoth;
        }

        /**
         * @brief This function calculates the inverse hyperbolic cotangent using the
         * identity i-e asech(x) = acosh(1/x).
         * @param arg The parameter on which the operation is performed.
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 inverse_secant_hyperbolic(const float1000& arg) {
            const float1000 normalized_argument{constants::real_one / arg};
            const float1000 asech{ acosh(normalized_argument) };
            return asech;
        }

        /**
         * @brief This function calculates the inverse hyperbolic cotangent using the
         * identity i-e acsch(x) = asinh(1/x).
         * @param arg The parameter on which the operation is performed.
         * @return The calculated result after the operation is successfully performed.
         */
        inline float1000 inverse_cosecant_hyperbolic(const float1000& arg) {
            const float1000 normalized_argument{ constants::real_one / arg };
            const float1000 acsch{ asinh(normalized_argument) };
            return acsch;
        }

    } // namespace real

    /**
     * @brief This namespace contains the definition for derived trigonometric
     * functions and their inverses for complex numbers. Overall the identities are
     * same; for both kind of arguments; so the documentation for the following
     * functions in this namespace will be concise. The containing functions are
     * inlined due to their small bodies, so that the compiler won't have to spend
     * extra time for inlining them.
     */
    namespace complex {
        /**
         * This function calculates the cotangent of complex number z.
         * @param arg The complex number on which the operation is performed.
         * @return The result of applying the already known reciprocal identity of
         * cotangent.
         */
        inline complex1000 cotangent(const complex1000& arg) {
            const complex1000 tangent_result{  std::tan(arg) };
            complex1000 cotangent_final_result{ constants::complex_one / tangent_result };
            return cotangent_final_result;
        }

        /**
         * This function calculates the secant of complex number z.
         * @param arg The complex number on which the operation is performed.
         * @return The result of applying the already known reciprocal identity of secant.
         */
        inline complex1000 secant(const complex1000& arg) {
            const complex1000 cosine_result{ std::cos(arg) };
            const complex1000 secant_final_result{ constants::complex_one / cosine_result };
            return secant_final_result;
        }

        /**
         * This function calculates the cosecant of complex number z.
         * @param arg The complex number on which the operation is performed
         * @return The result of applying the already known reciprocal identity of secant.
         */
        inline complex1000 cosecant(const complex1000& arg) {
            const complex1000 sine_result{ std::sin(arg) };
            complex1000 cosecant_final_result{ constants::complex_one / sine_result };
            return cosecant_final_result;
        }

        /**
         * This function calculates the inverse cotangent of complex number z.
         * @param arg The complex number on which the operation is performed.
         * @return The result of applying the reciprocal identity of cotangent.
         */
        inline complex1000 inverse_cotangent(const complex1000& arg) {
            const complex1000 normalized_argument{ constants::complex_one / arg };
            complex1000 icot_result{ std::atan(normalized_argument) };
            return icot_result;
        }

        /**
         * This function calculates the inverse secant of complex number z.
         * @param arg The complex number on which the operation is performed.
         * @return The result of applying the reciprocal identity of secant.
         */
        inline complex1000 inverse_secant(const complex1000& arg) {
            const complex1000 normalized_argument{ constants::complex_one / arg };
            complex1000 isec_result{ std::acos(normalized_argument) };
            return isec_result;
        }

        /**
         * This function calculates the inverse cosecant of complex number z.
         * @param arg The complex number on which the operation is performed
         * @return The result of applying the reciprocal identity of cosecant.
         */
        inline complex1000 inverse_cosecant(const complex1000& arg) {
            const complex1000 normalized_argument{ constants::complex_one / arg };
            complex1000 icsc_result{ std::asin(normalized_argument) };
            return icsc_result;
        }

        /**
         * This function calculates the hyperbolic cotangent of complex number z.
         * @param arg The complex number on which the operation is performed.
         * @return The result of applying the reciprocal identity of cotangent hyperbolic.
         */
        inline complex1000 cotangent_hyperbolic(const complex1000& arg) {
            const complex1000 tangent_hyperbolic_result{ std::tanh(arg) };
            complex1000 cotangent_h_result{ constants::complex_one / tangent_hyperbolic_result };
            return cotangent_h_result;
        }

        /**
         * This function calculates the hyperbolic secant of complex number z.
         * @param arg The complex number on which the operation is performed.
         * @return The result of applying the reciprocal identity of secant hyperbolic.
         */
        inline complex1000 secant_hyperbolic(const complex1000& arg) {
            const complex1000 cosine_hyperbolic_result{ std::cosh(arg) };
            complex1000 secant_h_result{  constants::complex_one / cosine_hyperbolic_result };
            return secant_h_result;
        }

        /**
         * This function calculates the hyperbolic cosecant of complex number z.
         * @param arg The complex number on which the operation is performed.
         * @return The result of applying the reciprocal identity of cosecant hyperbolic.
         */
        inline complex1000 cosecant_hyperbolic(const complex1000& arg) {
            const complex1000 sine_hyperbolic_result{ std::sinh(arg) };
            complex1000 cosecant_h_final_result{ constants::complex_one / sine_hyperbolic_result };
            return cosecant_h_final_result;
        }

        /**
         * This function calculates the inverse hyperbolic cotangent of complex number z.
         * @param arg The complex number on which the operation is performed.
         * @return The result of applying the reciprocal identity of cotangent hyperbolic.
         */
        inline complex1000 inverse_cotangent_hyperbolic(const complex1000& arg) {
            const complex1000 normalized_argument{constants::complex_one / arg};
            complex1000 icoth_result{ std::atanh(normalized_argument) };
            return icoth_result;
        }

        /**
         * This function calculates the inverse hyperbolic secant of complex number z.
         * @param arg The complex number on which the operation is performed.
         * @return The result of applying the reciprocal identity of secant hyperbolic.
         */
        inline complex1000 inverse_secant_hyperbolic(const complex1000& arg) {
            const complex1000 normalized_argument{constants::complex_one / arg};
            complex1000 isech_result{ std::acosh(normalized_argument) };
            return isech_result;
        }

        /**
         * This function calculates the inverse hyperbolic cosecant of complex number z.
         * @param arg The complex number on which the operation is performed
         * @return The result of applying the reciprocal identity of cosecant hyperbolic.
         */
        inline complex1000 inverse_cosecant_hyperbolic(const complex1000& arg) {
            const complex1000 normalized_argument{ constants::complex_one / arg };
            complex1000 icsch_result{ std::asinh(normalized_argument) };
            return icsch_result;
        }
    } // namespace complex
} // namespace mmqli::core::trigonometry
#endif // TRIGONOMETRY_HPP`