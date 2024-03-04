# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;
use Encode;

########################################################################
package Profiling;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

}

########################################################################
package Profiling::ResourceBucket;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{name} = Encode::decode("ascii", $self->{_io}->read_bytes(21));
    $self->{thread} = $self->{_io}->read_u1();
    $self->{mutex} = $self->{_io}->read_u1();
    $self->{cv} = $self->{_io}->read_u1();
    $self->{io} = $self->{_io}->read_u1();
    $self->{heap_bytes_alloc} = $self->{_io}->read_u4le();
    $self->{heap_bytes_free} = $self->{_io}->read_u4le();
    $self->{io_write} = $self->{_io}->read_u4le();
    $self->{io_read} = $self->{_io}->read_u4le();
}

sub name {
    my ($self) = @_;
    return $self->{name};
}

sub thread {
    my ($self) = @_;
    return $self->{thread};
}

sub mutex {
    my ($self) = @_;
    return $self->{mutex};
}

sub cv {
    my ($self) = @_;
    return $self->{cv};
}

sub io {
    my ($self) = @_;
    return $self->{io};
}

sub heap_bytes_alloc {
    my ($self) = @_;
    return $self->{heap_bytes_alloc};
}

sub heap_bytes_free {
    my ($self) = @_;
    return $self->{heap_bytes_free};
}

sub io_write {
    my ($self) = @_;
    return $self->{io_write};
}

sub io_read {
    my ($self) = @_;
    return $self->{io_read};
}

########################################################################
package Profiling::MsgProfilingSystemInfo;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{total_cpu_time} = $self->{_io}->read_u8le();
    $self->{age} = $self->{_io}->read_u8le();
    $self->{n_threads} = $self->{_io}->read_u1();
    $self->{heap_usage} = $self->{_io}->read_u4le();
}

sub total_cpu_time {
    my ($self) = @_;
    return $self->{total_cpu_time};
}

sub age {
    my ($self) = @_;
    return $self->{age};
}

sub n_threads {
    my ($self) = @_;
    return $self->{n_threads};
}

sub heap_usage {
    my ($self) = @_;
    return $self->{heap_usage};
}

########################################################################
package Profiling::MsgMeasurementPoint;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{total_time} = $self->{_io}->read_u4le();
    $self->{num_executions} = $self->{_io}->read_u2le();
    $self->{min} = $self->{_io}->read_u4le();
    $self->{max} = $self->{_io}->read_u4le();
    $self->{return_addr} = $self->{_io}->read_u8le();
    $self->{id} = $self->{_io}->read_u8le();
    $self->{slice_time} = $self->{_io}->read_u8le();
    $self->{line} = $self->{_io}->read_u2le();
    $self->{func} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub total_time {
    my ($self) = @_;
    return $self->{total_time};
}

sub num_executions {
    my ($self) = @_;
    return $self->{num_executions};
}

sub min {
    my ($self) = @_;
    return $self->{min};
}

sub max {
    my ($self) = @_;
    return $self->{max};
}

sub return_addr {
    my ($self) = @_;
    return $self->{return_addr};
}

sub id {
    my ($self) = @_;
    return $self->{id};
}

sub slice_time {
    my ($self) = @_;
    return $self->{slice_time};
}

sub line {
    my ($self) = @_;
    return $self->{line};
}

sub func {
    my ($self) = @_;
    return $self->{func};
}

########################################################################
package Profiling::MsgProfilingResourceCounter;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{seq_no} = $self->{_io}->read_u1();
    $self->{seq_len} = $self->{_io}->read_u1();
    $self->{buckets} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{buckets}}, Profiling::ResourceBucket->new($self->{_io}, $self, $self->{_root});
    }
}

sub seq_no {
    my ($self) = @_;
    return $self->{seq_no};
}

sub seq_len {
    my ($self) = @_;
    return $self->{seq_len};
}

sub buckets {
    my ($self) = @_;
    return $self->{buckets};
}

########################################################################
package Profiling::MsgProfilingThreadInfo;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{total_cpu_time} = $self->{_io}->read_u8le();
    $self->{age} = $self->{_io}->read_u8le();
    $self->{state} = $self->{_io}->read_u1();
    $self->{stack_size} = $self->{_io}->read_u4le();
    $self->{stack_usage} = $self->{_io}->read_u4le();
    $self->{name} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub total_cpu_time {
    my ($self) = @_;
    return $self->{total_cpu_time};
}

sub age {
    my ($self) = @_;
    return $self->{age};
}

sub state {
    my ($self) = @_;
    return $self->{state};
}

sub stack_size {
    my ($self) = @_;
    return $self->{stack_size};
}

sub stack_usage {
    my ($self) = @_;
    return $self->{stack_usage};
}

sub name {
    my ($self) = @_;
    return $self->{name};
}

1;
