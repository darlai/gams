/**
 * Copyright (c) 2015 Carnegie Mellon University. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following acknowledgments and disclaimers.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * 3. The names "Carnegie Mellon University," "SEI" and/or "Software
 *    Engineering Institute" shall not be used to endorse or promote products
 *    derived from this software without prior written permission. For written
 *    permission, please contact permission@sei.cmu.edu.
 * 
 * 4. Products derived from this software may not be called "SEI" nor may "SEI"
 *    appear in their names without prior written permission of
 *    permission@sei.cmu.edu.
 * 
 * 5. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 * 
 *      This material is based upon work funded and supported by the Department
 *      of Defense under Contract No. FA8721-05-C-0003 with Carnegie Mellon
 *      University for the operation of the Software Engineering Institute, a
 *      federally funded research and development center. Any opinions,
 *      findings and conclusions or recommendations expressed in this material
 *      are those of the author(s) and do not necessarily reflect the views of
 *      the United States Department of Defense.
 * 
 *      NO WARRANTY. THIS CARNEGIE MELLON UNIVERSITY AND SOFTWARE ENGINEERING
 *      INSTITUTE MATERIAL IS FURNISHED ON AN "AS-IS" BASIS. CARNEGIE MELLON
 *      UNIVERSITY MAKES NO WARRANTIES OF ANY KIND, EITHER EXPRESSED OR
 *      IMPLIED, AS TO ANY MATTER INCLUDING, BUT NOT LIMITED TO, WARRANTY OF
 *      FITNESS FOR PURPOSE OR MERCHANTABILITY, EXCLUSIVITY, OR RESULTS
 *      OBTAINED FROM USE OF THE MATERIAL. CARNEGIE MELLON UNIVERSITY DOES
 *      NOT MAKE ANY WARRANTY OF ANY KIND WITH RESPECT TO FREEDOM FROM PATENT,
 *      TRADEMARK, OR COPYRIGHT INFRINGEMENT.
 * 
 *      This material has been approved for public release and unlimited
 *      distribution.
 **/

/**
 * @file Rotation.inl
 * @author James Edmondson <jedmondson@gmail.com>
 *
 * This file contains inline functions for the Rotation
 **/

#ifndef _GAMS_POSE_ROTATION_INL_
#define _GAMS_POSE_ROTATION_INL_

#include <stdexcept>

#include "Rotation.h"

namespace gams
{
  namespace pose
  {
    inline constexpr RotationVector::RotationVector(
            double rx, double ry, double rz)
      : rx_(rx), ry_(ry), rz_(rz) {}

    inline constexpr RotationVector::RotationVector(
            double x, double y, double z, double angle)
      : rx_(x * DEG_TO_RAD(angle)),
        ry_(y * DEG_TO_RAD(angle)),
        rz_(z * DEG_TO_RAD(angle)) {}

    inline RotationVector::RotationVector(
        const madara::knowledge::containers::DoubleVector &vec)
      : rx_(vec[0]), ry_(vec[1]), rz_(vec[2]) {}

    inline RotationVector::RotationVector(
        const madara::knowledge::containers::NativeDoubleVector &vec)
      : rx_(vec[0]), ry_(vec[1]), rz_(vec[2]) {}

    inline constexpr RotationVector::RotationVector()
      : rx_(0), ry_(0), rz_(0) {}

    inline constexpr bool RotationVector::is_set () const
    {
      return rx_ != INVAL_COORD || ry_ != INVAL_COORD || rz_ != INVAL_COORD;
    }

    inline constexpr bool RotationVector::is_zero() const
    {
      return rx_ == 0 && ry_ == 0 && rz_ == 0;
    }

    inline constexpr bool RotationVector::operator==(
            const RotationVector &other) const
    {
      return rx_ == other.rx_ && ry_ == other.ry_ && rz_ == other.rz_;
    }

    inline std::string RotationVector::name()
    {
      return "Rotation";
    }

    inline constexpr double RotationVector::rx() const { return rx_; }
    inline constexpr double RotationVector::ry() const { return ry_; }
    inline constexpr double RotationVector::rz() const { return rz_; }

    inline double RotationVector::rx(double new_rx) { return rx_ = new_rx; }
    inline double RotationVector::ry(double new_ry) { return ry_ = new_ry; }
    inline double RotationVector::rz(double new_rz) { return rz_ = new_rz; }

    inline RotationVector &RotationVector::as_vec()
    {
      return static_cast<BaseType &>(*this);
    }

    inline constexpr const RotationVector &RotationVector::as_vec() const
    {
      return static_cast<const BaseType &>(*this);
    }

    inline constexpr int RotationVector::size() const
    {
      return 3;
    }

    inline constexpr double RotationVector::get(int i) const
    {
      return i == 0 ? rx() :
             i == 1 ? ry() :
             i == 2 ? rz() :
            throw std::range_error("Index out of bounds for Rotation");
    }

    inline double RotationVector::set(int i, double val)
    {
      if(i == 0)
        return rx(val);
      else if(i == 1)
        return ry(val);
      else if(i == 2)
        return rz(val);
      throw std::range_error("Index out of bounds for Rotation");
    }

    inline std::ostream &operator<<(std::ostream &o, const RotationVector &rot)
    {
      o << "(" << rot.rx() << "," << rot.ry() << "," << rot.rz() << ")";
      return o;
    }

    inline std::string Rotation::to_string (const std::string & delimiter,
      const std::string & unset_identifier) const
    {
      std::stringstream buffer;

      if (rx () != DBL_MAX)
        buffer << rx ();
      else
        buffer << unset_identifier;

      buffer << delimiter;

      if (ry () != DBL_MAX)
        buffer << ry ();
      else
        buffer << unset_identifier;

      buffer << delimiter;

      if (rz () != DBL_MAX)
        buffer << rz ();
      else
        buffer << unset_identifier;

      return buffer.str ();
    }

    inline Rotation::Rotation(double rx, double ry, double rz)
      : RotationVector(rx, ry, rz),
        Coordinate() {}

    inline constexpr Rotation::Rotation(
            const ReferenceFrame &frame, double rx, double ry, double rz)
      : RotationVector(rx, ry, rz),
        Coordinate(frame) {}

    inline Rotation::Rotation(double x, double y, double z, double angle)
      : RotationVector(x, y, z, angle), Coordinate() {}

    inline constexpr Rotation::Rotation(
       const ReferenceFrame &frame, double x, double y, double z, double angle)
      : RotationVector(x, y, z, angle), Coordinate(frame) {}

    template<typename U>
    inline Rotation::Rotation(double rx, double ry, double rz, U u)
      : RotationVector(u.to_radians(rx), u.to_radians(ry), u.to_radians(rz)),
        Coordinate() {}

    template<typename U>
    inline constexpr Rotation::Rotation(
            const ReferenceFrame &frame, double rx, double ry, double rz, U u)
      : RotationVector(u.to_radians(rx), u.to_radians(ry), u.to_radians(rz)),
        Coordinate(frame) {}

    template<typename U>
    inline Rotation::Rotation(double x, double y, double z, double angle, U u)
      : RotationVector(x, y, z, u.to_radians(angle)), Coordinate() {}

    template<typename U>
    inline constexpr Rotation::Rotation(
       const ReferenceFrame &frame, double x, double y, double z,
                                    double angle, U u)
      : RotationVector(x, y, z, u.to_radians(angle)), Coordinate(frame) {}

    inline Rotation::Rotation() : RotationVector(), Coordinate() {}

    inline Rotation::Rotation(const Quaternion &quat)
      : RotationVector(quat), Coordinate() {}

    inline Rotation::Rotation(
          const ReferenceFrame &frame, const Quaternion &quat)
      : RotationVector(quat), Coordinate(frame) {}

    inline Rotation::Rotation(
                const ReferenceFrame &new_frame, const Rotation &orig)
      : RotationVector(orig), Coordinate(orig.frame())
    {
      transform_this_to(new_frame);
    }

    inline Rotation::Rotation(
        const madara::knowledge::containers::DoubleVector &vec)
      : RotationVector(vec), Coordinate() {}

    inline Rotation::Rotation(const ReferenceFrame &frame,
        const madara::knowledge::containers::DoubleVector &vec)
      : RotationVector(vec), Coordinate(frame) {}

    inline Rotation::Rotation(
        const madara::knowledge::containers::NativeDoubleVector &vec)
      : RotationVector(vec), Coordinate() {}

    inline Rotation::Rotation(
        const ReferenceFrame &frame,
        const madara::knowledge::containers::NativeDoubleVector &vec)
      : RotationVector(vec), Coordinate(frame) {}

    inline double Rotation::angle_to(const Rotation &target) const
    {
      return distance_to(target);
    }

    template<typename U>
    inline double Rotation::angle_to (const Rotation &target, U u) const
    {
      return u.from_radians (distance_to (target));
    }
  }
}

#endif