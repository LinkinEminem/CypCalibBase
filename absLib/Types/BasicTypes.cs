using System;

namespace absLib.Types
{
    public readonly struct Point3D
    {
        public double X { get; }
        public double Y { get; }
        public double Z { get; }

        public Point3D(double x, double y, double z) => (X, Y, Z) = (x, y, z);
        
        public static Point3D operator +(Point3D a, Point3D b)
            => new Point3D(a.X + b.X, a.Y + b.Y, a.Z + b.Z);
        
        public static Point3D operator -(Point3D a, Point3D b)
            => new Point3D(a.X - b.X, a.Y - b.Y, a.Z - b.Z);

        public double Dot(Point3D b)
        {
            return X*b.X + Y*b.Y + Z*b.Z;
        }

        public double Norm()
        {
            return Math.Sqrt(X*X + Y*Y + Z*Z);
        }
    }

    public readonly struct Point6D
    {
        public Point3D Pt { get;  }
        public Point3D Vec { get; }

        public double X => Pt.X;
        public double Y => Pt.Y;
        public double Z => Pt.Z;
        public double A => Vec.X;
        public double B => Vec.Y;
        public double C => Vec.Z;

        public Point6D(double x, double y, double z, double a, double b, double c)
        {
            Pt = new Point3D(x, y, z);
            Vec = new Point3D(a, b, c);
        }

        public Point6D(Point3D pt, Point3D vec)
        {
            Pt = pt;
            Vec = vec;
        }
        
        public static Point6D operator +(Point6D a, Point6D b)
            => new Point6D(a.X + b.X, a.Y + b.Y, a.Z + b.Z, a.A + b.A, a.B + b.B, a.C + b.C);
        
        public static Point6D operator -(Point6D a, Point6D b)
            => new Point6D(a.X - b.X, a.Y - b.Y, a.Z - b.Z, a.A - b.A, a.B - b.B, a.C - b.C);
        
        public double Dot(Point6D b)
        {
            return X*b.X + Y*b.Y + Z*b.Z + A*b.A + B*b.B + C*b.C;
        }

        public double Norm()
        {
            return Math.Sqrt(X*X + Y*Y + Z*Z + A*A + B*B + C*C);
        }
    }
}
