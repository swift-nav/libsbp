# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;
use Encode;

########################################################################
package Linux;

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
package Linux::MsgLinuxSocketUsage;

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

    $self->{avg_queue_depth} = $self->{_io}->read_u4le();
    $self->{max_queue_depth} = $self->{_io}->read_u4le();
    $self->{socket_state_counts} = ();
    my $n_socket_state_counts = 16;
    for (my $i = 0; $i < $n_socket_state_counts; $i++) {
        push @{$self->{socket_state_counts}}, $self->{_io}->read_u2le();
    }
    $self->{socket_type_counts} = ();
    my $n_socket_type_counts = 16;
    for (my $i = 0; $i < $n_socket_type_counts; $i++) {
        push @{$self->{socket_type_counts}}, $self->{_io}->read_u2le();
    }
}

sub avg_queue_depth {
    my ($self) = @_;
    return $self->{avg_queue_depth};
}

sub max_queue_depth {
    my ($self) = @_;
    return $self->{max_queue_depth};
}

sub socket_state_counts {
    my ($self) = @_;
    return $self->{socket_state_counts};
}

sub socket_type_counts {
    my ($self) = @_;
    return $self->{socket_type_counts};
}

########################################################################
package Linux::MsgLinuxSysState;

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

    $self->{mem_total} = $self->{_io}->read_u2le();
    $self->{pcpu} = $self->{_io}->read_u1();
    $self->{pmem} = $self->{_io}->read_u1();
    $self->{procs_starting} = $self->{_io}->read_u2le();
    $self->{procs_stopping} = $self->{_io}->read_u2le();
    $self->{pid_count} = $self->{_io}->read_u2le();
    $self->{time} = $self->{_io}->read_u4le();
    $self->{flags} = $self->{_io}->read_u1();
}

sub mem_total {
    my ($self) = @_;
    return $self->{mem_total};
}

sub pcpu {
    my ($self) = @_;
    return $self->{pcpu};
}

sub pmem {
    my ($self) = @_;
    return $self->{pmem};
}

sub procs_starting {
    my ($self) = @_;
    return $self->{procs_starting};
}

sub procs_stopping {
    my ($self) = @_;
    return $self->{procs_stopping};
}

sub pid_count {
    my ($self) = @_;
    return $self->{pid_count};
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Linux::MsgLinuxCpuStateDepA;

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

    $self->{index} = $self->{_io}->read_u1();
    $self->{pid} = $self->{_io}->read_u2le();
    $self->{pcpu} = $self->{_io}->read_u1();
    $self->{tname} = Encode::decode("ascii", $self->{_io}->read_bytes(15));
    $self->{cmdline} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub index {
    my ($self) = @_;
    return $self->{index};
}

sub pid {
    my ($self) = @_;
    return $self->{pid};
}

sub pcpu {
    my ($self) = @_;
    return $self->{pcpu};
}

sub tname {
    my ($self) = @_;
    return $self->{tname};
}

sub cmdline {
    my ($self) = @_;
    return $self->{cmdline};
}

########################################################################
package Linux::MsgLinuxMemState;

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

    $self->{index} = $self->{_io}->read_u1();
    $self->{pid} = $self->{_io}->read_u2le();
    $self->{pmem} = $self->{_io}->read_u1();
    $self->{time} = $self->{_io}->read_u4le();
    $self->{flags} = $self->{_io}->read_u1();
    $self->{tname} = Encode::decode("ascii", $self->{_io}->read_bytes(15));
    $self->{cmdline} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub index {
    my ($self) = @_;
    return $self->{index};
}

sub pid {
    my ($self) = @_;
    return $self->{pid};
}

sub pmem {
    my ($self) = @_;
    return $self->{pmem};
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub tname {
    my ($self) = @_;
    return $self->{tname};
}

sub cmdline {
    my ($self) = @_;
    return $self->{cmdline};
}

########################################################################
package Linux::MsgLinuxProcessFdCount;

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

    $self->{index} = $self->{_io}->read_u1();
    $self->{pid} = $self->{_io}->read_u2le();
    $self->{fd_count} = $self->{_io}->read_u2le();
    $self->{cmdline} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub index {
    my ($self) = @_;
    return $self->{index};
}

sub pid {
    my ($self) = @_;
    return $self->{pid};
}

sub fd_count {
    my ($self) = @_;
    return $self->{fd_count};
}

sub cmdline {
    my ($self) = @_;
    return $self->{cmdline};
}

########################################################################
package Linux::MsgLinuxMemStateDepA;

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

    $self->{index} = $self->{_io}->read_u1();
    $self->{pid} = $self->{_io}->read_u2le();
    $self->{pmem} = $self->{_io}->read_u1();
    $self->{tname} = Encode::decode("ascii", $self->{_io}->read_bytes(15));
    $self->{cmdline} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub index {
    my ($self) = @_;
    return $self->{index};
}

sub pid {
    my ($self) = @_;
    return $self->{pid};
}

sub pmem {
    my ($self) = @_;
    return $self->{pmem};
}

sub tname {
    my ($self) = @_;
    return $self->{tname};
}

sub cmdline {
    my ($self) = @_;
    return $self->{cmdline};
}

########################################################################
package Linux::MsgLinuxProcessSocketQueues;

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

    $self->{index} = $self->{_io}->read_u1();
    $self->{pid} = $self->{_io}->read_u2le();
    $self->{recv_queued} = $self->{_io}->read_u2le();
    $self->{send_queued} = $self->{_io}->read_u2le();
    $self->{socket_types} = $self->{_io}->read_u2le();
    $self->{socket_states} = $self->{_io}->read_u2le();
    $self->{address_of_largest} = Encode::decode("ascii", $self->{_io}->read_bytes(64));
    $self->{cmdline} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub index {
    my ($self) = @_;
    return $self->{index};
}

sub pid {
    my ($self) = @_;
    return $self->{pid};
}

sub recv_queued {
    my ($self) = @_;
    return $self->{recv_queued};
}

sub send_queued {
    my ($self) = @_;
    return $self->{send_queued};
}

sub socket_types {
    my ($self) = @_;
    return $self->{socket_types};
}

sub socket_states {
    my ($self) = @_;
    return $self->{socket_states};
}

sub address_of_largest {
    my ($self) = @_;
    return $self->{address_of_largest};
}

sub cmdline {
    my ($self) = @_;
    return $self->{cmdline};
}

########################################################################
package Linux::MsgLinuxSysStateDepA;

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

    $self->{mem_total} = $self->{_io}->read_u2le();
    $self->{pcpu} = $self->{_io}->read_u1();
    $self->{pmem} = $self->{_io}->read_u1();
    $self->{procs_starting} = $self->{_io}->read_u2le();
    $self->{procs_stopping} = $self->{_io}->read_u2le();
    $self->{pid_count} = $self->{_io}->read_u2le();
}

sub mem_total {
    my ($self) = @_;
    return $self->{mem_total};
}

sub pcpu {
    my ($self) = @_;
    return $self->{pcpu};
}

sub pmem {
    my ($self) = @_;
    return $self->{pmem};
}

sub procs_starting {
    my ($self) = @_;
    return $self->{procs_starting};
}

sub procs_stopping {
    my ($self) = @_;
    return $self->{procs_stopping};
}

sub pid_count {
    my ($self) = @_;
    return $self->{pid_count};
}

########################################################################
package Linux::MsgLinuxProcessFdSummary;

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

    $self->{sys_fd_count} = $self->{_io}->read_u4le();
    $self->{most_opened} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub sys_fd_count {
    my ($self) = @_;
    return $self->{sys_fd_count};
}

sub most_opened {
    my ($self) = @_;
    return $self->{most_opened};
}

########################################################################
package Linux::MsgLinuxCpuState;

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

    $self->{index} = $self->{_io}->read_u1();
    $self->{pid} = $self->{_io}->read_u2le();
    $self->{pcpu} = $self->{_io}->read_u1();
    $self->{time} = $self->{_io}->read_u4le();
    $self->{flags} = $self->{_io}->read_u1();
    $self->{tname} = Encode::decode("ascii", $self->{_io}->read_bytes(15));
    $self->{cmdline} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub index {
    my ($self) = @_;
    return $self->{index};
}

sub pid {
    my ($self) = @_;
    return $self->{pid};
}

sub pcpu {
    my ($self) = @_;
    return $self->{pcpu};
}

sub time {
    my ($self) = @_;
    return $self->{time};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub tname {
    my ($self) = @_;
    return $self->{tname};
}

sub cmdline {
    my ($self) = @_;
    return $self->{cmdline};
}

########################################################################
package Linux::MsgLinuxProcessSocketCounts;

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

    $self->{index} = $self->{_io}->read_u1();
    $self->{pid} = $self->{_io}->read_u2le();
    $self->{socket_count} = $self->{_io}->read_u2le();
    $self->{socket_types} = $self->{_io}->read_u2le();
    $self->{socket_states} = $self->{_io}->read_u2le();
    $self->{cmdline} = Encode::decode("ascii", $self->{_io}->read_bytes_full());
}

sub index {
    my ($self) = @_;
    return $self->{index};
}

sub pid {
    my ($self) = @_;
    return $self->{pid};
}

sub socket_count {
    my ($self) = @_;
    return $self->{socket_count};
}

sub socket_types {
    my ($self) = @_;
    return $self->{socket_types};
}

sub socket_states {
    my ($self) = @_;
    return $self->{socket_states};
}

sub cmdline {
    my ($self) = @_;
    return $self->{cmdline};
}

1;
