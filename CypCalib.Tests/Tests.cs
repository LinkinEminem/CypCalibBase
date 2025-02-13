using System;
using CypCalib.Core.Domain.Shared;
using Xunit;

namespace CypCalib.Tests
{
    public class Point3DTest
    {
        [Fact]
        public void Addition_Operator()
        {
            var a = new Point3D(1, 2, 3);
            var b = new Point3D(4, 5, 6);
            var rst = a + b;
            Assert.Equal(new Point3D(5, 7, 9), rst);
        }

        [Fact]
        public void Subtraction_Operator()
        {
            var a = new Point3D(1, 2, 3);
            var b = new Point3D(4, 5, 6);
            var rst = a - b;
            Assert.Equal(new Point3D(-3, -3, -3), rst);
        }

        [Fact]
        public void DotMulti()
        {
            var a = new Point3D(1, 2, 3);
            var b = new Point3D(4, 5, 6);
            var rst = a.Dot(b);
            Assert.Equal(32, rst);
        }

        [Fact]
        public void Norm()
        {
            var a = new Point3D(1, 2, 3);
            var rst = a.Norm();
            Assert.Equal(Math.Sqrt(14), rst);
        }
    }
}