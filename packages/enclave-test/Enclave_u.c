#include "Enclave_u.h"
#include <errno.h>

typedef struct ms_ecall_allocate_t {
	EnclaveBuffer ms_retval;
	const uint8_t* ms_buffer;
	uintptr_t ms_length;
} ms_ecall_allocate_t;

typedef struct ms_ecall_init_bootstrap_t {
	sgx_status_t ms_retval;
	uint8_t* ms_seed;
} ms_ecall_init_bootstrap_t;

typedef struct ms_ecall_key_gen_t {
	sgx_status_t ms_retval;
	uint8_t* ms_public_key;
} ms_ecall_key_gen_t;

typedef struct ms_ecall_get_attestation_report_t {
	sgx_status_t ms_retval;
} ms_ecall_get_attestation_report_t;

typedef struct ms_ecall_authenticate_new_node_t {
	NodeAuthResult ms_retval;
	const uint8_t* ms_cert;
	uintptr_t ms_cert_len;
	uint8_t* ms_seed;
} ms_ecall_authenticate_new_node_t;

typedef struct ms_ecall_init_node_t {
	sgx_status_t ms_retval;
	const uint8_t* ms_master_cert;
	uintptr_t ms_master_cert_len;
	const uint8_t* ms_encrypted_seed;
	uintptr_t ms_encrypted_seed_len;
} ms_ecall_init_node_t;

typedef struct ms_ecall_init_t {
	InitResult ms_retval;
	Ctx ms_context;
	uint64_t ms_gas_limit;
	uint64_t* ms_used_gas;
	const uint8_t* ms_contract;
	uintptr_t ms_contract_len;
	const uint8_t* ms_env;
	uintptr_t ms_env_len;
	const uint8_t* ms_msg;
	uintptr_t ms_msg_len;
} ms_ecall_init_t;

typedef struct ms_ecall_handle_t {
	HandleResult ms_retval;
	Ctx ms_context;
	uint64_t ms_gas_limit;
	uint64_t* ms_used_gas;
	const uint8_t* ms_contract;
	uintptr_t ms_contract_len;
	const uint8_t* ms_env;
	uintptr_t ms_env_len;
	const uint8_t* ms_msg;
	uintptr_t ms_msg_len;
} ms_ecall_handle_t;

typedef struct ms_ecall_query_t {
	QueryResult ms_retval;
	Ctx ms_context;
	uint64_t ms_gas_limit;
	uint64_t* ms_used_gas;
	const uint8_t* ms_contract;
	uintptr_t ms_contract_len;
	const uint8_t* ms_msg;
	uintptr_t ms_msg_len;
} ms_ecall_query_t;

typedef struct ms_ecall_run_tests_t {
	uint32_t ms_retval;
} ms_ecall_run_tests_t;

typedef struct ms_t_global_init_ecall_t {
	uint64_t ms_id;
	const uint8_t* ms_path;
	size_t ms_len;
} ms_t_global_init_ecall_t;

typedef struct ms_ocall_allocate_t {
	UserSpaceBuffer ms_retval;
	const uint8_t* ms_buffer;
	uintptr_t ms_length;
} ms_ocall_allocate_t;

typedef struct ms_ocall_read_db_t {
	OcallReturn ms_retval;
	Ctx ms_context;
	UntrustedVmError* ms_vm_error;
	uint64_t* ms_gas_used;
	EnclaveBuffer* ms_value;
	const uint8_t* ms_key;
	uintptr_t ms_key_len;
} ms_ocall_read_db_t;

typedef struct ms_ocall_remove_db_t {
	OcallReturn ms_retval;
	Ctx ms_context;
	UntrustedVmError* ms_vm_error;
	uint64_t* ms_gas_used;
	const uint8_t* ms_key;
	uintptr_t ms_key_len;
} ms_ocall_remove_db_t;

typedef struct ms_ocall_write_db_t {
	OcallReturn ms_retval;
	Ctx ms_context;
	UntrustedVmError* ms_vm_error;
	uint64_t* ms_gas_used;
	const uint8_t* ms_key;
	uintptr_t ms_key_len;
	const uint8_t* ms_value;
	uintptr_t ms_value_len;
} ms_ocall_write_db_t;

typedef struct ms_ocall_sgx_init_quote_t {
	sgx_status_t ms_retval;
	sgx_target_info_t* ms_ret_ti;
	sgx_epid_group_id_t* ms_ret_gid;
} ms_ocall_sgx_init_quote_t;

typedef struct ms_ocall_get_ias_socket_t {
	sgx_status_t ms_retval;
	int* ms_ret_fd;
} ms_ocall_get_ias_socket_t;

typedef struct ms_ocall_get_quote_t {
	sgx_status_t ms_retval;
	uint8_t* ms_p_sigrl;
	uint32_t ms_sigrl_len;
	sgx_report_t* ms_report;
	sgx_quote_sign_type_t ms_quote_type;
	sgx_spid_t* ms_p_spid;
	sgx_quote_nonce_t* ms_p_nonce;
	sgx_report_t* ms_p_qe_report;
	sgx_quote_t* ms_p_quote;
	uint32_t ms_maxlen;
	uint32_t* ms_p_quote_len;
} ms_ocall_get_quote_t;

typedef struct ms_ocall_get_update_info_t {
	sgx_status_t ms_retval;
	sgx_platform_info_t* ms_platformBlob;
	int32_t ms_enclaveTrusted;
	sgx_update_info_bit_t* ms_update_info;
} ms_ocall_get_update_info_t;

typedef struct ms_u_thread_set_event_ocall_t {
	int ms_retval;
	int* ms_error;
	const void* ms_tcs;
} ms_u_thread_set_event_ocall_t;

typedef struct ms_u_thread_wait_event_ocall_t {
	int ms_retval;
	int* ms_error;
	const void* ms_tcs;
	const struct timespec* ms_timeout;
} ms_u_thread_wait_event_ocall_t;

typedef struct ms_u_thread_set_multiple_events_ocall_t {
	int ms_retval;
	int* ms_error;
	const void** ms_tcss;
	int ms_total;
} ms_u_thread_set_multiple_events_ocall_t;

typedef struct ms_u_thread_setwait_events_ocall_t {
	int ms_retval;
	int* ms_error;
	const void* ms_waiter_tcs;
	const void* ms_self_tcs;
	const struct timespec* ms_timeout;
} ms_u_thread_setwait_events_ocall_t;

typedef struct ms_u_clock_gettime_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_clk_id;
	struct timespec* ms_tp;
} ms_u_clock_gettime_ocall_t;

typedef struct ms_u_read_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	void* ms_buf;
	size_t ms_count;
} ms_u_read_ocall_t;

typedef struct ms_u_pread64_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	void* ms_buf;
	size_t ms_count;
	int64_t ms_offset;
} ms_u_pread64_ocall_t;

typedef struct ms_u_readv_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	const struct iovec* ms_iov;
	int ms_iovcnt;
} ms_u_readv_ocall_t;

typedef struct ms_u_preadv64_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	const struct iovec* ms_iov;
	int ms_iovcnt;
	int64_t ms_offset;
} ms_u_preadv64_ocall_t;

typedef struct ms_u_write_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	const void* ms_buf;
	size_t ms_count;
} ms_u_write_ocall_t;

typedef struct ms_u_pwrite64_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	const void* ms_buf;
	size_t ms_count;
	int64_t ms_offset;
} ms_u_pwrite64_ocall_t;

typedef struct ms_u_writev_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	const struct iovec* ms_iov;
	int ms_iovcnt;
} ms_u_writev_ocall_t;

typedef struct ms_u_pwritev64_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	const struct iovec* ms_iov;
	int ms_iovcnt;
	int64_t ms_offset;
} ms_u_pwritev64_ocall_t;

typedef struct ms_u_fcntl_arg0_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	int ms_cmd;
} ms_u_fcntl_arg0_ocall_t;

typedef struct ms_u_fcntl_arg1_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	int ms_cmd;
	int ms_arg;
} ms_u_fcntl_arg1_ocall_t;

typedef struct ms_u_ioctl_arg0_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	int ms_request;
} ms_u_ioctl_arg0_ocall_t;

typedef struct ms_u_ioctl_arg1_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	int ms_request;
	int* ms_arg;
} ms_u_ioctl_arg1_ocall_t;

typedef struct ms_u_close_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
} ms_u_close_ocall_t;

typedef struct ms_u_malloc_ocall_t {
	void* ms_retval;
	int* ms_error;
	size_t ms_size;
} ms_u_malloc_ocall_t;

typedef struct ms_u_free_ocall_t {
	void* ms_p;
} ms_u_free_ocall_t;

typedef struct ms_u_mmap_ocall_t {
	void* ms_retval;
	int* ms_error;
	void* ms_start;
	size_t ms_length;
	int ms_prot;
	int ms_flags;
	int ms_fd;
	int64_t ms_offset;
} ms_u_mmap_ocall_t;

typedef struct ms_u_munmap_ocall_t {
	int ms_retval;
	int* ms_error;
	void* ms_start;
	size_t ms_length;
} ms_u_munmap_ocall_t;

typedef struct ms_u_msync_ocall_t {
	int ms_retval;
	int* ms_error;
	void* ms_addr;
	size_t ms_length;
	int ms_flags;
} ms_u_msync_ocall_t;

typedef struct ms_u_mprotect_ocall_t {
	int ms_retval;
	int* ms_error;
	void* ms_addr;
	size_t ms_length;
	int ms_prot;
} ms_u_mprotect_ocall_t;

typedef struct ms_u_open_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_pathname;
	int ms_flags;
} ms_u_open_ocall_t;

typedef struct ms_u_open64_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	int ms_oflag;
	int ms_mode;
} ms_u_open64_ocall_t;

typedef struct ms_u_fstat_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	struct stat_t* ms_buf;
} ms_u_fstat_ocall_t;

typedef struct ms_u_fstat64_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	struct stat64_t* ms_buf;
} ms_u_fstat64_ocall_t;

typedef struct ms_u_stat_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	struct stat_t* ms_buf;
} ms_u_stat_ocall_t;

typedef struct ms_u_stat64_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	struct stat64_t* ms_buf;
} ms_u_stat64_ocall_t;

typedef struct ms_u_lstat_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	struct stat_t* ms_buf;
} ms_u_lstat_ocall_t;

typedef struct ms_u_lstat64_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	struct stat64_t* ms_buf;
} ms_u_lstat64_ocall_t;

typedef struct ms_u_lseek_ocall_t {
	uint64_t ms_retval;
	int* ms_error;
	int ms_fd;
	int64_t ms_offset;
	int ms_whence;
} ms_u_lseek_ocall_t;

typedef struct ms_u_lseek64_ocall_t {
	int64_t ms_retval;
	int* ms_error;
	int ms_fd;
	int64_t ms_offset;
	int ms_whence;
} ms_u_lseek64_ocall_t;

typedef struct ms_u_ftruncate_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	int64_t ms_length;
} ms_u_ftruncate_ocall_t;

typedef struct ms_u_ftruncate64_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	int64_t ms_length;
} ms_u_ftruncate64_ocall_t;

typedef struct ms_u_truncate_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	int64_t ms_length;
} ms_u_truncate_ocall_t;

typedef struct ms_u_truncate64_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	int64_t ms_length;
} ms_u_truncate64_ocall_t;

typedef struct ms_u_fsync_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
} ms_u_fsync_ocall_t;

typedef struct ms_u_fdatasync_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
} ms_u_fdatasync_ocall_t;

typedef struct ms_u_fchmod_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	uint32_t ms_mode;
} ms_u_fchmod_ocall_t;

typedef struct ms_u_unlink_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_pathname;
} ms_u_unlink_ocall_t;

typedef struct ms_u_link_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_oldpath;
	const char* ms_newpath;
} ms_u_link_ocall_t;

typedef struct ms_u_rename_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_oldpath;
	const char* ms_newpath;
} ms_u_rename_ocall_t;

typedef struct ms_u_chmod_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	uint32_t ms_mode;
} ms_u_chmod_ocall_t;

typedef struct ms_u_readlink_ocall_t {
	size_t ms_retval;
	int* ms_error;
	const char* ms_path;
	char* ms_buf;
	size_t ms_bufsz;
} ms_u_readlink_ocall_t;

typedef struct ms_u_symlink_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path1;
	const char* ms_path2;
} ms_u_symlink_ocall_t;

typedef struct ms_u_realpath_ocall_t {
	char* ms_retval;
	int* ms_error;
	const char* ms_pathname;
} ms_u_realpath_ocall_t;

typedef struct ms_u_mkdir_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_pathname;
	uint32_t ms_mode;
} ms_u_mkdir_ocall_t;

typedef struct ms_u_rmdir_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_pathname;
} ms_u_rmdir_ocall_t;

typedef struct ms_u_opendir_ocall_t {
	void* ms_retval;
	int* ms_error;
	const char* ms_pathname;
} ms_u_opendir_ocall_t;

typedef struct ms_u_readdir64_r_ocall_t {
	int ms_retval;
	void* ms_dirp;
	struct dirent64_t* ms_entry;
	struct dirent64_t** ms_result;
} ms_u_readdir64_r_ocall_t;

typedef struct ms_u_closedir_ocall_t {
	int ms_retval;
	int* ms_error;
	void* ms_dirp;
} ms_u_closedir_ocall_t;

typedef struct ms_u_dirfd_ocall_t {
	int ms_retval;
	int* ms_error;
	void* ms_dirp;
} ms_u_dirfd_ocall_t;

typedef struct ms_u_fstatat64_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_dirfd;
	const char* ms_pathname;
	struct stat64_t* ms_buf;
	int ms_flags;
} ms_u_fstatat64_ocall_t;

typedef struct ms_u_getaddrinfo_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_node;
	const char* ms_service;
	const struct addrinfo* ms_hints;
	struct addrinfo** ms_res;
} ms_u_getaddrinfo_ocall_t;

typedef struct ms_u_freeaddrinfo_ocall_t {
	struct addrinfo* ms_res;
} ms_u_freeaddrinfo_ocall_t;

typedef struct ms_u_gai_strerror_ocall_t {
	char* ms_retval;
	int ms_errcode;
} ms_u_gai_strerror_ocall_t;

typedef struct ms_u_socket_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_domain;
	int ms_ty;
	int ms_protocol;
} ms_u_socket_ocall_t;

typedef struct ms_u_socketpair_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_domain;
	int ms_ty;
	int ms_protocol;
	int* ms_sv;
} ms_u_socketpair_ocall_t;

typedef struct ms_u_bind_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_sockfd;
	const struct sockaddr* ms_addr;
	socklen_t ms_addrlen;
} ms_u_bind_ocall_t;

typedef struct ms_u_listen_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_sockfd;
	int ms_backlog;
} ms_u_listen_ocall_t;

typedef struct ms_u_accept_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_sockfd;
	struct sockaddr* ms_addr;
	socklen_t ms_addrlen_in;
	socklen_t* ms_addrlen_out;
} ms_u_accept_ocall_t;

typedef struct ms_u_accept4_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_sockfd;
	struct sockaddr* ms_addr;
	socklen_t ms_addrlen_in;
	socklen_t* ms_addrlen_out;
	int ms_flags;
} ms_u_accept4_ocall_t;

typedef struct ms_u_connect_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_sockfd;
	const struct sockaddr* ms_addr;
	socklen_t ms_addrlen;
} ms_u_connect_ocall_t;

typedef struct ms_u_recv_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_sockfd;
	void* ms_buf;
	size_t ms_len;
	int ms_flags;
} ms_u_recv_ocall_t;

typedef struct ms_u_recvfrom_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_sockfd;
	void* ms_buf;
	size_t ms_len;
	int ms_flags;
	struct sockaddr* ms_src_addr;
	socklen_t ms_addrlen_in;
	socklen_t* ms_addrlen_out;
} ms_u_recvfrom_ocall_t;

typedef struct ms_u_recvmsg_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_sockfd;
	struct msghdr* ms_msg;
	int ms_flags;
} ms_u_recvmsg_ocall_t;

typedef struct ms_u_send_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_sockfd;
	const void* ms_buf;
	size_t ms_len;
	int ms_flags;
} ms_u_send_ocall_t;

typedef struct ms_u_sendto_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_sockfd;
	const void* ms_buf;
	size_t ms_len;
	int ms_flags;
	const struct sockaddr* ms_dest_addr;
	socklen_t ms_addrlen;
} ms_u_sendto_ocall_t;

typedef struct ms_u_sendmsg_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_sockfd;
	const struct msghdr* ms_msg;
	int ms_flags;
} ms_u_sendmsg_ocall_t;

typedef struct ms_u_getsockopt_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_sockfd;
	int ms_level;
	int ms_optname;
	void* ms_optval;
	socklen_t ms_optlen_in;
	socklen_t* ms_optlen_out;
} ms_u_getsockopt_ocall_t;

typedef struct ms_u_setsockopt_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_sockfd;
	int ms_level;
	int ms_optname;
	const void* ms_optval;
	socklen_t ms_optlen;
} ms_u_setsockopt_ocall_t;

typedef struct ms_u_getsockname_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_sockfd;
	struct sockaddr* ms_addr;
	socklen_t ms_addrlen_in;
	socklen_t* ms_addrlen_out;
} ms_u_getsockname_ocall_t;

typedef struct ms_u_getpeername_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_sockfd;
	struct sockaddr* ms_addr;
	socklen_t ms_addrlen_in;
	socklen_t* ms_addrlen_out;
} ms_u_getpeername_ocall_t;

typedef struct ms_u_shutdown_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_sockfd;
	int ms_how;
} ms_u_shutdown_ocall_t;

typedef struct ms_u_poll_ocall_t {
	int ms_retval;
	int* ms_error;
	struct pollfd* ms_fds;
	nfds_t ms_nfds;
	int ms_timeout;
} ms_u_poll_ocall_t;

typedef struct ms_u_epoll_create1_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_flags;
} ms_u_epoll_create1_ocall_t;

typedef struct ms_u_epoll_ctl_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_epfd;
	int ms_op;
	int ms_fd;
	struct epoll_event* ms_event;
} ms_u_epoll_ctl_ocall_t;

typedef struct ms_u_epoll_wait_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_epfd;
	struct epoll_event* ms_events;
	int ms_maxevents;
	int ms_timeout;
} ms_u_epoll_wait_ocall_t;

typedef struct ms_sgx_oc_cpuidex_t {
	int* ms_cpuinfo;
	int ms_leaf;
	int ms_subleaf;
} ms_sgx_oc_cpuidex_t;

typedef struct ms_sgx_thread_wait_untrusted_event_ocall_t {
	int ms_retval;
	const void* ms_self;
} ms_sgx_thread_wait_untrusted_event_ocall_t;

typedef struct ms_sgx_thread_set_untrusted_event_ocall_t {
	int ms_retval;
	const void* ms_waiter;
} ms_sgx_thread_set_untrusted_event_ocall_t;

typedef struct ms_sgx_thread_setwait_untrusted_events_ocall_t {
	int ms_retval;
	const void* ms_waiter;
	const void* ms_self;
} ms_sgx_thread_setwait_untrusted_events_ocall_t;

typedef struct ms_sgx_thread_set_multiple_untrusted_events_ocall_t {
	int ms_retval;
	const void** ms_waiters;
	size_t ms_total;
} ms_sgx_thread_set_multiple_untrusted_events_ocall_t;

typedef struct ms_u_sgxprotectedfs_exclusive_file_open_t {
	void* ms_retval;
	const char* ms_filename;
	uint8_t ms_read_only;
	int64_t* ms_file_size;
	int32_t* ms_error_code;
} ms_u_sgxprotectedfs_exclusive_file_open_t;

typedef struct ms_u_sgxprotectedfs_check_if_file_exists_t {
	uint8_t ms_retval;
	const char* ms_filename;
} ms_u_sgxprotectedfs_check_if_file_exists_t;

typedef struct ms_u_sgxprotectedfs_fread_node_t {
	int32_t ms_retval;
	void* ms_f;
	uint64_t ms_node_number;
	uint8_t* ms_buffer;
	uint32_t ms_node_size;
} ms_u_sgxprotectedfs_fread_node_t;

typedef struct ms_u_sgxprotectedfs_fwrite_node_t {
	int32_t ms_retval;
	void* ms_f;
	uint64_t ms_node_number;
	uint8_t* ms_buffer;
	uint32_t ms_node_size;
} ms_u_sgxprotectedfs_fwrite_node_t;

typedef struct ms_u_sgxprotectedfs_fclose_t {
	int32_t ms_retval;
	void* ms_f;
} ms_u_sgxprotectedfs_fclose_t;

typedef struct ms_u_sgxprotectedfs_fflush_t {
	uint8_t ms_retval;
	void* ms_f;
} ms_u_sgxprotectedfs_fflush_t;

typedef struct ms_u_sgxprotectedfs_remove_t {
	int32_t ms_retval;
	const char* ms_filename;
} ms_u_sgxprotectedfs_remove_t;

typedef struct ms_u_sgxprotectedfs_recovery_file_open_t {
	void* ms_retval;
	const char* ms_filename;
} ms_u_sgxprotectedfs_recovery_file_open_t;

typedef struct ms_u_sgxprotectedfs_fwrite_recovery_node_t {
	uint8_t ms_retval;
	void* ms_f;
	uint8_t* ms_data;
	uint32_t ms_data_length;
} ms_u_sgxprotectedfs_fwrite_recovery_node_t;

typedef struct ms_u_sgxprotectedfs_do_file_recovery_t {
	int32_t ms_retval;
	const char* ms_filename;
	const char* ms_recovery_filename;
	uint32_t ms_node_size;
} ms_u_sgxprotectedfs_do_file_recovery_t;

typedef struct ms_u_getenv_ocall_t {
	char* ms_retval;
	const char* ms_name;
} ms_u_getenv_ocall_t;

static sgx_status_t SGX_CDECL Enclave_ocall_allocate(void* pms)
{
	ms_ocall_allocate_t* ms = SGX_CAST(ms_ocall_allocate_t*, pms);
	ms->ms_retval = ocall_allocate(ms->ms_buffer, ms->ms_length);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_ocall_read_db(void* pms)
{
	ms_ocall_read_db_t* ms = SGX_CAST(ms_ocall_read_db_t*, pms);
	ms->ms_retval = ocall_read_db(ms->ms_context, ms->ms_vm_error, ms->ms_gas_used, ms->ms_value, ms->ms_key, ms->ms_key_len);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_ocall_remove_db(void* pms)
{
	ms_ocall_remove_db_t* ms = SGX_CAST(ms_ocall_remove_db_t*, pms);
	ms->ms_retval = ocall_remove_db(ms->ms_context, ms->ms_vm_error, ms->ms_gas_used, ms->ms_key, ms->ms_key_len);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_ocall_write_db(void* pms)
{
	ms_ocall_write_db_t* ms = SGX_CAST(ms_ocall_write_db_t*, pms);
	ms->ms_retval = ocall_write_db(ms->ms_context, ms->ms_vm_error, ms->ms_gas_used, ms->ms_key, ms->ms_key_len, ms->ms_value, ms->ms_value_len);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_ocall_sgx_init_quote(void* pms)
{
	ms_ocall_sgx_init_quote_t* ms = SGX_CAST(ms_ocall_sgx_init_quote_t*, pms);
	ms->ms_retval = ocall_sgx_init_quote(ms->ms_ret_ti, ms->ms_ret_gid);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_ocall_get_ias_socket(void* pms)
{
	ms_ocall_get_ias_socket_t* ms = SGX_CAST(ms_ocall_get_ias_socket_t*, pms);
	ms->ms_retval = ocall_get_ias_socket(ms->ms_ret_fd);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_ocall_get_quote(void* pms)
{
	ms_ocall_get_quote_t* ms = SGX_CAST(ms_ocall_get_quote_t*, pms);
	ms->ms_retval = ocall_get_quote(ms->ms_p_sigrl, ms->ms_sigrl_len, ms->ms_report, ms->ms_quote_type, ms->ms_p_spid, ms->ms_p_nonce, ms->ms_p_qe_report, ms->ms_p_quote, ms->ms_maxlen, ms->ms_p_quote_len);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_ocall_get_update_info(void* pms)
{
	ms_ocall_get_update_info_t* ms = SGX_CAST(ms_ocall_get_update_info_t*, pms);
	ms->ms_retval = ocall_get_update_info(ms->ms_platformBlob, ms->ms_enclaveTrusted, ms->ms_update_info);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_thread_set_event_ocall(void* pms)
{
	ms_u_thread_set_event_ocall_t* ms = SGX_CAST(ms_u_thread_set_event_ocall_t*, pms);
	ms->ms_retval = u_thread_set_event_ocall(ms->ms_error, ms->ms_tcs);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_thread_wait_event_ocall(void* pms)
{
	ms_u_thread_wait_event_ocall_t* ms = SGX_CAST(ms_u_thread_wait_event_ocall_t*, pms);
	ms->ms_retval = u_thread_wait_event_ocall(ms->ms_error, ms->ms_tcs, ms->ms_timeout);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_thread_set_multiple_events_ocall(void* pms)
{
	ms_u_thread_set_multiple_events_ocall_t* ms = SGX_CAST(ms_u_thread_set_multiple_events_ocall_t*, pms);
	ms->ms_retval = u_thread_set_multiple_events_ocall(ms->ms_error, ms->ms_tcss, ms->ms_total);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_thread_setwait_events_ocall(void* pms)
{
	ms_u_thread_setwait_events_ocall_t* ms = SGX_CAST(ms_u_thread_setwait_events_ocall_t*, pms);
	ms->ms_retval = u_thread_setwait_events_ocall(ms->ms_error, ms->ms_waiter_tcs, ms->ms_self_tcs, ms->ms_timeout);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_clock_gettime_ocall(void* pms)
{
	ms_u_clock_gettime_ocall_t* ms = SGX_CAST(ms_u_clock_gettime_ocall_t*, pms);
	ms->ms_retval = u_clock_gettime_ocall(ms->ms_error, ms->ms_clk_id, ms->ms_tp);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_read_ocall(void* pms)
{
	ms_u_read_ocall_t* ms = SGX_CAST(ms_u_read_ocall_t*, pms);
	ms->ms_retval = u_read_ocall(ms->ms_error, ms->ms_fd, ms->ms_buf, ms->ms_count);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_pread64_ocall(void* pms)
{
	ms_u_pread64_ocall_t* ms = SGX_CAST(ms_u_pread64_ocall_t*, pms);
	ms->ms_retval = u_pread64_ocall(ms->ms_error, ms->ms_fd, ms->ms_buf, ms->ms_count, ms->ms_offset);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_readv_ocall(void* pms)
{
	ms_u_readv_ocall_t* ms = SGX_CAST(ms_u_readv_ocall_t*, pms);
	ms->ms_retval = u_readv_ocall(ms->ms_error, ms->ms_fd, ms->ms_iov, ms->ms_iovcnt);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_preadv64_ocall(void* pms)
{
	ms_u_preadv64_ocall_t* ms = SGX_CAST(ms_u_preadv64_ocall_t*, pms);
	ms->ms_retval = u_preadv64_ocall(ms->ms_error, ms->ms_fd, ms->ms_iov, ms->ms_iovcnt, ms->ms_offset);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_write_ocall(void* pms)
{
	ms_u_write_ocall_t* ms = SGX_CAST(ms_u_write_ocall_t*, pms);
	ms->ms_retval = u_write_ocall(ms->ms_error, ms->ms_fd, ms->ms_buf, ms->ms_count);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_pwrite64_ocall(void* pms)
{
	ms_u_pwrite64_ocall_t* ms = SGX_CAST(ms_u_pwrite64_ocall_t*, pms);
	ms->ms_retval = u_pwrite64_ocall(ms->ms_error, ms->ms_fd, ms->ms_buf, ms->ms_count, ms->ms_offset);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_writev_ocall(void* pms)
{
	ms_u_writev_ocall_t* ms = SGX_CAST(ms_u_writev_ocall_t*, pms);
	ms->ms_retval = u_writev_ocall(ms->ms_error, ms->ms_fd, ms->ms_iov, ms->ms_iovcnt);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_pwritev64_ocall(void* pms)
{
	ms_u_pwritev64_ocall_t* ms = SGX_CAST(ms_u_pwritev64_ocall_t*, pms);
	ms->ms_retval = u_pwritev64_ocall(ms->ms_error, ms->ms_fd, ms->ms_iov, ms->ms_iovcnt, ms->ms_offset);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fcntl_arg0_ocall(void* pms)
{
	ms_u_fcntl_arg0_ocall_t* ms = SGX_CAST(ms_u_fcntl_arg0_ocall_t*, pms);
	ms->ms_retval = u_fcntl_arg0_ocall(ms->ms_error, ms->ms_fd, ms->ms_cmd);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fcntl_arg1_ocall(void* pms)
{
	ms_u_fcntl_arg1_ocall_t* ms = SGX_CAST(ms_u_fcntl_arg1_ocall_t*, pms);
	ms->ms_retval = u_fcntl_arg1_ocall(ms->ms_error, ms->ms_fd, ms->ms_cmd, ms->ms_arg);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_ioctl_arg0_ocall(void* pms)
{
	ms_u_ioctl_arg0_ocall_t* ms = SGX_CAST(ms_u_ioctl_arg0_ocall_t*, pms);
	ms->ms_retval = u_ioctl_arg0_ocall(ms->ms_error, ms->ms_fd, ms->ms_request);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_ioctl_arg1_ocall(void* pms)
{
	ms_u_ioctl_arg1_ocall_t* ms = SGX_CAST(ms_u_ioctl_arg1_ocall_t*, pms);
	ms->ms_retval = u_ioctl_arg1_ocall(ms->ms_error, ms->ms_fd, ms->ms_request, ms->ms_arg);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_close_ocall(void* pms)
{
	ms_u_close_ocall_t* ms = SGX_CAST(ms_u_close_ocall_t*, pms);
	ms->ms_retval = u_close_ocall(ms->ms_error, ms->ms_fd);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_malloc_ocall(void* pms)
{
	ms_u_malloc_ocall_t* ms = SGX_CAST(ms_u_malloc_ocall_t*, pms);
	ms->ms_retval = u_malloc_ocall(ms->ms_error, ms->ms_size);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_free_ocall(void* pms)
{
	ms_u_free_ocall_t* ms = SGX_CAST(ms_u_free_ocall_t*, pms);
	u_free_ocall(ms->ms_p);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_mmap_ocall(void* pms)
{
	ms_u_mmap_ocall_t* ms = SGX_CAST(ms_u_mmap_ocall_t*, pms);
	ms->ms_retval = u_mmap_ocall(ms->ms_error, ms->ms_start, ms->ms_length, ms->ms_prot, ms->ms_flags, ms->ms_fd, ms->ms_offset);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_munmap_ocall(void* pms)
{
	ms_u_munmap_ocall_t* ms = SGX_CAST(ms_u_munmap_ocall_t*, pms);
	ms->ms_retval = u_munmap_ocall(ms->ms_error, ms->ms_start, ms->ms_length);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_msync_ocall(void* pms)
{
	ms_u_msync_ocall_t* ms = SGX_CAST(ms_u_msync_ocall_t*, pms);
	ms->ms_retval = u_msync_ocall(ms->ms_error, ms->ms_addr, ms->ms_length, ms->ms_flags);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_mprotect_ocall(void* pms)
{
	ms_u_mprotect_ocall_t* ms = SGX_CAST(ms_u_mprotect_ocall_t*, pms);
	ms->ms_retval = u_mprotect_ocall(ms->ms_error, ms->ms_addr, ms->ms_length, ms->ms_prot);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_open_ocall(void* pms)
{
	ms_u_open_ocall_t* ms = SGX_CAST(ms_u_open_ocall_t*, pms);
	ms->ms_retval = u_open_ocall(ms->ms_error, ms->ms_pathname, ms->ms_flags);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_open64_ocall(void* pms)
{
	ms_u_open64_ocall_t* ms = SGX_CAST(ms_u_open64_ocall_t*, pms);
	ms->ms_retval = u_open64_ocall(ms->ms_error, ms->ms_path, ms->ms_oflag, ms->ms_mode);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fstat_ocall(void* pms)
{
	ms_u_fstat_ocall_t* ms = SGX_CAST(ms_u_fstat_ocall_t*, pms);
	ms->ms_retval = u_fstat_ocall(ms->ms_error, ms->ms_fd, ms->ms_buf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fstat64_ocall(void* pms)
{
	ms_u_fstat64_ocall_t* ms = SGX_CAST(ms_u_fstat64_ocall_t*, pms);
	ms->ms_retval = u_fstat64_ocall(ms->ms_error, ms->ms_fd, ms->ms_buf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_stat_ocall(void* pms)
{
	ms_u_stat_ocall_t* ms = SGX_CAST(ms_u_stat_ocall_t*, pms);
	ms->ms_retval = u_stat_ocall(ms->ms_error, ms->ms_path, ms->ms_buf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_stat64_ocall(void* pms)
{
	ms_u_stat64_ocall_t* ms = SGX_CAST(ms_u_stat64_ocall_t*, pms);
	ms->ms_retval = u_stat64_ocall(ms->ms_error, ms->ms_path, ms->ms_buf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_lstat_ocall(void* pms)
{
	ms_u_lstat_ocall_t* ms = SGX_CAST(ms_u_lstat_ocall_t*, pms);
	ms->ms_retval = u_lstat_ocall(ms->ms_error, ms->ms_path, ms->ms_buf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_lstat64_ocall(void* pms)
{
	ms_u_lstat64_ocall_t* ms = SGX_CAST(ms_u_lstat64_ocall_t*, pms);
	ms->ms_retval = u_lstat64_ocall(ms->ms_error, ms->ms_path, ms->ms_buf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_lseek_ocall(void* pms)
{
	ms_u_lseek_ocall_t* ms = SGX_CAST(ms_u_lseek_ocall_t*, pms);
	ms->ms_retval = u_lseek_ocall(ms->ms_error, ms->ms_fd, ms->ms_offset, ms->ms_whence);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_lseek64_ocall(void* pms)
{
	ms_u_lseek64_ocall_t* ms = SGX_CAST(ms_u_lseek64_ocall_t*, pms);
	ms->ms_retval = u_lseek64_ocall(ms->ms_error, ms->ms_fd, ms->ms_offset, ms->ms_whence);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_ftruncate_ocall(void* pms)
{
	ms_u_ftruncate_ocall_t* ms = SGX_CAST(ms_u_ftruncate_ocall_t*, pms);
	ms->ms_retval = u_ftruncate_ocall(ms->ms_error, ms->ms_fd, ms->ms_length);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_ftruncate64_ocall(void* pms)
{
	ms_u_ftruncate64_ocall_t* ms = SGX_CAST(ms_u_ftruncate64_ocall_t*, pms);
	ms->ms_retval = u_ftruncate64_ocall(ms->ms_error, ms->ms_fd, ms->ms_length);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_truncate_ocall(void* pms)
{
	ms_u_truncate_ocall_t* ms = SGX_CAST(ms_u_truncate_ocall_t*, pms);
	ms->ms_retval = u_truncate_ocall(ms->ms_error, ms->ms_path, ms->ms_length);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_truncate64_ocall(void* pms)
{
	ms_u_truncate64_ocall_t* ms = SGX_CAST(ms_u_truncate64_ocall_t*, pms);
	ms->ms_retval = u_truncate64_ocall(ms->ms_error, ms->ms_path, ms->ms_length);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fsync_ocall(void* pms)
{
	ms_u_fsync_ocall_t* ms = SGX_CAST(ms_u_fsync_ocall_t*, pms);
	ms->ms_retval = u_fsync_ocall(ms->ms_error, ms->ms_fd);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fdatasync_ocall(void* pms)
{
	ms_u_fdatasync_ocall_t* ms = SGX_CAST(ms_u_fdatasync_ocall_t*, pms);
	ms->ms_retval = u_fdatasync_ocall(ms->ms_error, ms->ms_fd);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fchmod_ocall(void* pms)
{
	ms_u_fchmod_ocall_t* ms = SGX_CAST(ms_u_fchmod_ocall_t*, pms);
	ms->ms_retval = u_fchmod_ocall(ms->ms_error, ms->ms_fd, ms->ms_mode);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_unlink_ocall(void* pms)
{
	ms_u_unlink_ocall_t* ms = SGX_CAST(ms_u_unlink_ocall_t*, pms);
	ms->ms_retval = u_unlink_ocall(ms->ms_error, ms->ms_pathname);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_link_ocall(void* pms)
{
	ms_u_link_ocall_t* ms = SGX_CAST(ms_u_link_ocall_t*, pms);
	ms->ms_retval = u_link_ocall(ms->ms_error, ms->ms_oldpath, ms->ms_newpath);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_rename_ocall(void* pms)
{
	ms_u_rename_ocall_t* ms = SGX_CAST(ms_u_rename_ocall_t*, pms);
	ms->ms_retval = u_rename_ocall(ms->ms_error, ms->ms_oldpath, ms->ms_newpath);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_chmod_ocall(void* pms)
{
	ms_u_chmod_ocall_t* ms = SGX_CAST(ms_u_chmod_ocall_t*, pms);
	ms->ms_retval = u_chmod_ocall(ms->ms_error, ms->ms_path, ms->ms_mode);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_readlink_ocall(void* pms)
{
	ms_u_readlink_ocall_t* ms = SGX_CAST(ms_u_readlink_ocall_t*, pms);
	ms->ms_retval = u_readlink_ocall(ms->ms_error, ms->ms_path, ms->ms_buf, ms->ms_bufsz);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_symlink_ocall(void* pms)
{
	ms_u_symlink_ocall_t* ms = SGX_CAST(ms_u_symlink_ocall_t*, pms);
	ms->ms_retval = u_symlink_ocall(ms->ms_error, ms->ms_path1, ms->ms_path2);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_realpath_ocall(void* pms)
{
	ms_u_realpath_ocall_t* ms = SGX_CAST(ms_u_realpath_ocall_t*, pms);
	ms->ms_retval = u_realpath_ocall(ms->ms_error, ms->ms_pathname);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_mkdir_ocall(void* pms)
{
	ms_u_mkdir_ocall_t* ms = SGX_CAST(ms_u_mkdir_ocall_t*, pms);
	ms->ms_retval = u_mkdir_ocall(ms->ms_error, ms->ms_pathname, ms->ms_mode);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_rmdir_ocall(void* pms)
{
	ms_u_rmdir_ocall_t* ms = SGX_CAST(ms_u_rmdir_ocall_t*, pms);
	ms->ms_retval = u_rmdir_ocall(ms->ms_error, ms->ms_pathname);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_opendir_ocall(void* pms)
{
	ms_u_opendir_ocall_t* ms = SGX_CAST(ms_u_opendir_ocall_t*, pms);
	ms->ms_retval = u_opendir_ocall(ms->ms_error, ms->ms_pathname);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_readdir64_r_ocall(void* pms)
{
	ms_u_readdir64_r_ocall_t* ms = SGX_CAST(ms_u_readdir64_r_ocall_t*, pms);
	ms->ms_retval = u_readdir64_r_ocall(ms->ms_dirp, ms->ms_entry, ms->ms_result);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_closedir_ocall(void* pms)
{
	ms_u_closedir_ocall_t* ms = SGX_CAST(ms_u_closedir_ocall_t*, pms);
	ms->ms_retval = u_closedir_ocall(ms->ms_error, ms->ms_dirp);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_dirfd_ocall(void* pms)
{
	ms_u_dirfd_ocall_t* ms = SGX_CAST(ms_u_dirfd_ocall_t*, pms);
	ms->ms_retval = u_dirfd_ocall(ms->ms_error, ms->ms_dirp);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fstatat64_ocall(void* pms)
{
	ms_u_fstatat64_ocall_t* ms = SGX_CAST(ms_u_fstatat64_ocall_t*, pms);
	ms->ms_retval = u_fstatat64_ocall(ms->ms_error, ms->ms_dirfd, ms->ms_pathname, ms->ms_buf, ms->ms_flags);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_getaddrinfo_ocall(void* pms)
{
	ms_u_getaddrinfo_ocall_t* ms = SGX_CAST(ms_u_getaddrinfo_ocall_t*, pms);
	ms->ms_retval = u_getaddrinfo_ocall(ms->ms_error, ms->ms_node, ms->ms_service, ms->ms_hints, ms->ms_res);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_freeaddrinfo_ocall(void* pms)
{
	ms_u_freeaddrinfo_ocall_t* ms = SGX_CAST(ms_u_freeaddrinfo_ocall_t*, pms);
	u_freeaddrinfo_ocall(ms->ms_res);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_gai_strerror_ocall(void* pms)
{
	ms_u_gai_strerror_ocall_t* ms = SGX_CAST(ms_u_gai_strerror_ocall_t*, pms);
	ms->ms_retval = u_gai_strerror_ocall(ms->ms_errcode);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_socket_ocall(void* pms)
{
	ms_u_socket_ocall_t* ms = SGX_CAST(ms_u_socket_ocall_t*, pms);
	ms->ms_retval = u_socket_ocall(ms->ms_error, ms->ms_domain, ms->ms_ty, ms->ms_protocol);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_socketpair_ocall(void* pms)
{
	ms_u_socketpair_ocall_t* ms = SGX_CAST(ms_u_socketpair_ocall_t*, pms);
	ms->ms_retval = u_socketpair_ocall(ms->ms_error, ms->ms_domain, ms->ms_ty, ms->ms_protocol, ms->ms_sv);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_bind_ocall(void* pms)
{
	ms_u_bind_ocall_t* ms = SGX_CAST(ms_u_bind_ocall_t*, pms);
	ms->ms_retval = u_bind_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_addr, ms->ms_addrlen);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_listen_ocall(void* pms)
{
	ms_u_listen_ocall_t* ms = SGX_CAST(ms_u_listen_ocall_t*, pms);
	ms->ms_retval = u_listen_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_backlog);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_accept_ocall(void* pms)
{
	ms_u_accept_ocall_t* ms = SGX_CAST(ms_u_accept_ocall_t*, pms);
	ms->ms_retval = u_accept_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_addr, ms->ms_addrlen_in, ms->ms_addrlen_out);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_accept4_ocall(void* pms)
{
	ms_u_accept4_ocall_t* ms = SGX_CAST(ms_u_accept4_ocall_t*, pms);
	ms->ms_retval = u_accept4_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_addr, ms->ms_addrlen_in, ms->ms_addrlen_out, ms->ms_flags);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_connect_ocall(void* pms)
{
	ms_u_connect_ocall_t* ms = SGX_CAST(ms_u_connect_ocall_t*, pms);
	ms->ms_retval = u_connect_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_addr, ms->ms_addrlen);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_recv_ocall(void* pms)
{
	ms_u_recv_ocall_t* ms = SGX_CAST(ms_u_recv_ocall_t*, pms);
	ms->ms_retval = u_recv_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_buf, ms->ms_len, ms->ms_flags);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_recvfrom_ocall(void* pms)
{
	ms_u_recvfrom_ocall_t* ms = SGX_CAST(ms_u_recvfrom_ocall_t*, pms);
	ms->ms_retval = u_recvfrom_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_buf, ms->ms_len, ms->ms_flags, ms->ms_src_addr, ms->ms_addrlen_in, ms->ms_addrlen_out);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_recvmsg_ocall(void* pms)
{
	ms_u_recvmsg_ocall_t* ms = SGX_CAST(ms_u_recvmsg_ocall_t*, pms);
	ms->ms_retval = u_recvmsg_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_msg, ms->ms_flags);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_send_ocall(void* pms)
{
	ms_u_send_ocall_t* ms = SGX_CAST(ms_u_send_ocall_t*, pms);
	ms->ms_retval = u_send_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_buf, ms->ms_len, ms->ms_flags);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sendto_ocall(void* pms)
{
	ms_u_sendto_ocall_t* ms = SGX_CAST(ms_u_sendto_ocall_t*, pms);
	ms->ms_retval = u_sendto_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_buf, ms->ms_len, ms->ms_flags, ms->ms_dest_addr, ms->ms_addrlen);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sendmsg_ocall(void* pms)
{
	ms_u_sendmsg_ocall_t* ms = SGX_CAST(ms_u_sendmsg_ocall_t*, pms);
	ms->ms_retval = u_sendmsg_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_msg, ms->ms_flags);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_getsockopt_ocall(void* pms)
{
	ms_u_getsockopt_ocall_t* ms = SGX_CAST(ms_u_getsockopt_ocall_t*, pms);
	ms->ms_retval = u_getsockopt_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_level, ms->ms_optname, ms->ms_optval, ms->ms_optlen_in, ms->ms_optlen_out);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_setsockopt_ocall(void* pms)
{
	ms_u_setsockopt_ocall_t* ms = SGX_CAST(ms_u_setsockopt_ocall_t*, pms);
	ms->ms_retval = u_setsockopt_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_level, ms->ms_optname, ms->ms_optval, ms->ms_optlen);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_getsockname_ocall(void* pms)
{
	ms_u_getsockname_ocall_t* ms = SGX_CAST(ms_u_getsockname_ocall_t*, pms);
	ms->ms_retval = u_getsockname_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_addr, ms->ms_addrlen_in, ms->ms_addrlen_out);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_getpeername_ocall(void* pms)
{
	ms_u_getpeername_ocall_t* ms = SGX_CAST(ms_u_getpeername_ocall_t*, pms);
	ms->ms_retval = u_getpeername_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_addr, ms->ms_addrlen_in, ms->ms_addrlen_out);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_shutdown_ocall(void* pms)
{
	ms_u_shutdown_ocall_t* ms = SGX_CAST(ms_u_shutdown_ocall_t*, pms);
	ms->ms_retval = u_shutdown_ocall(ms->ms_error, ms->ms_sockfd, ms->ms_how);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_poll_ocall(void* pms)
{
	ms_u_poll_ocall_t* ms = SGX_CAST(ms_u_poll_ocall_t*, pms);
	ms->ms_retval = u_poll_ocall(ms->ms_error, ms->ms_fds, ms->ms_nfds, ms->ms_timeout);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_epoll_create1_ocall(void* pms)
{
	ms_u_epoll_create1_ocall_t* ms = SGX_CAST(ms_u_epoll_create1_ocall_t*, pms);
	ms->ms_retval = u_epoll_create1_ocall(ms->ms_error, ms->ms_flags);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_epoll_ctl_ocall(void* pms)
{
	ms_u_epoll_ctl_ocall_t* ms = SGX_CAST(ms_u_epoll_ctl_ocall_t*, pms);
	ms->ms_retval = u_epoll_ctl_ocall(ms->ms_error, ms->ms_epfd, ms->ms_op, ms->ms_fd, ms->ms_event);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_epoll_wait_ocall(void* pms)
{
	ms_u_epoll_wait_ocall_t* ms = SGX_CAST(ms_u_epoll_wait_ocall_t*, pms);
	ms->ms_retval = u_epoll_wait_ocall(ms->ms_error, ms->ms_epfd, ms->ms_events, ms->ms_maxevents, ms->ms_timeout);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_sgx_oc_cpuidex(void* pms)
{
	ms_sgx_oc_cpuidex_t* ms = SGX_CAST(ms_sgx_oc_cpuidex_t*, pms);
	sgx_oc_cpuidex(ms->ms_cpuinfo, ms->ms_leaf, ms->ms_subleaf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_sgx_thread_wait_untrusted_event_ocall(void* pms)
{
	ms_sgx_thread_wait_untrusted_event_ocall_t* ms = SGX_CAST(ms_sgx_thread_wait_untrusted_event_ocall_t*, pms);
	ms->ms_retval = sgx_thread_wait_untrusted_event_ocall(ms->ms_self);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_sgx_thread_set_untrusted_event_ocall(void* pms)
{
	ms_sgx_thread_set_untrusted_event_ocall_t* ms = SGX_CAST(ms_sgx_thread_set_untrusted_event_ocall_t*, pms);
	ms->ms_retval = sgx_thread_set_untrusted_event_ocall(ms->ms_waiter);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_sgx_thread_setwait_untrusted_events_ocall(void* pms)
{
	ms_sgx_thread_setwait_untrusted_events_ocall_t* ms = SGX_CAST(ms_sgx_thread_setwait_untrusted_events_ocall_t*, pms);
	ms->ms_retval = sgx_thread_setwait_untrusted_events_ocall(ms->ms_waiter, ms->ms_self);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_sgx_thread_set_multiple_untrusted_events_ocall(void* pms)
{
	ms_sgx_thread_set_multiple_untrusted_events_ocall_t* ms = SGX_CAST(ms_sgx_thread_set_multiple_untrusted_events_ocall_t*, pms);
	ms->ms_retval = sgx_thread_set_multiple_untrusted_events_ocall(ms->ms_waiters, ms->ms_total);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sgxprotectedfs_exclusive_file_open(void* pms)
{
	ms_u_sgxprotectedfs_exclusive_file_open_t* ms = SGX_CAST(ms_u_sgxprotectedfs_exclusive_file_open_t*, pms);
	ms->ms_retval = u_sgxprotectedfs_exclusive_file_open(ms->ms_filename, ms->ms_read_only, ms->ms_file_size, ms->ms_error_code);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sgxprotectedfs_check_if_file_exists(void* pms)
{
	ms_u_sgxprotectedfs_check_if_file_exists_t* ms = SGX_CAST(ms_u_sgxprotectedfs_check_if_file_exists_t*, pms);
	ms->ms_retval = u_sgxprotectedfs_check_if_file_exists(ms->ms_filename);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sgxprotectedfs_fread_node(void* pms)
{
	ms_u_sgxprotectedfs_fread_node_t* ms = SGX_CAST(ms_u_sgxprotectedfs_fread_node_t*, pms);
	ms->ms_retval = u_sgxprotectedfs_fread_node(ms->ms_f, ms->ms_node_number, ms->ms_buffer, ms->ms_node_size);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sgxprotectedfs_fwrite_node(void* pms)
{
	ms_u_sgxprotectedfs_fwrite_node_t* ms = SGX_CAST(ms_u_sgxprotectedfs_fwrite_node_t*, pms);
	ms->ms_retval = u_sgxprotectedfs_fwrite_node(ms->ms_f, ms->ms_node_number, ms->ms_buffer, ms->ms_node_size);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sgxprotectedfs_fclose(void* pms)
{
	ms_u_sgxprotectedfs_fclose_t* ms = SGX_CAST(ms_u_sgxprotectedfs_fclose_t*, pms);
	ms->ms_retval = u_sgxprotectedfs_fclose(ms->ms_f);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sgxprotectedfs_fflush(void* pms)
{
	ms_u_sgxprotectedfs_fflush_t* ms = SGX_CAST(ms_u_sgxprotectedfs_fflush_t*, pms);
	ms->ms_retval = u_sgxprotectedfs_fflush(ms->ms_f);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sgxprotectedfs_remove(void* pms)
{
	ms_u_sgxprotectedfs_remove_t* ms = SGX_CAST(ms_u_sgxprotectedfs_remove_t*, pms);
	ms->ms_retval = u_sgxprotectedfs_remove(ms->ms_filename);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sgxprotectedfs_recovery_file_open(void* pms)
{
	ms_u_sgxprotectedfs_recovery_file_open_t* ms = SGX_CAST(ms_u_sgxprotectedfs_recovery_file_open_t*, pms);
	ms->ms_retval = u_sgxprotectedfs_recovery_file_open(ms->ms_filename);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sgxprotectedfs_fwrite_recovery_node(void* pms)
{
	ms_u_sgxprotectedfs_fwrite_recovery_node_t* ms = SGX_CAST(ms_u_sgxprotectedfs_fwrite_recovery_node_t*, pms);
	ms->ms_retval = u_sgxprotectedfs_fwrite_recovery_node(ms->ms_f, ms->ms_data, ms->ms_data_length);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sgxprotectedfs_do_file_recovery(void* pms)
{
	ms_u_sgxprotectedfs_do_file_recovery_t* ms = SGX_CAST(ms_u_sgxprotectedfs_do_file_recovery_t*, pms);
	ms->ms_retval = u_sgxprotectedfs_do_file_recovery(ms->ms_filename, ms->ms_recovery_filename, ms->ms_node_size);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_getenv_ocall(void* pms)
{
	ms_u_getenv_ocall_t* ms = SGX_CAST(ms_u_getenv_ocall_t*, pms);
	ms->ms_retval = u_getenv_ocall(ms->ms_name);

	return SGX_SUCCESS;
}

static const struct {
	size_t nr_ocall;
	void * table[104];
} ocall_table_Enclave = {
	104,
	{
		(void*)Enclave_ocall_allocate,
		(void*)Enclave_ocall_read_db,
		(void*)Enclave_ocall_remove_db,
		(void*)Enclave_ocall_write_db,
		(void*)Enclave_ocall_sgx_init_quote,
		(void*)Enclave_ocall_get_ias_socket,
		(void*)Enclave_ocall_get_quote,
		(void*)Enclave_ocall_get_update_info,
		(void*)Enclave_u_thread_set_event_ocall,
		(void*)Enclave_u_thread_wait_event_ocall,
		(void*)Enclave_u_thread_set_multiple_events_ocall,
		(void*)Enclave_u_thread_setwait_events_ocall,
		(void*)Enclave_u_clock_gettime_ocall,
		(void*)Enclave_u_read_ocall,
		(void*)Enclave_u_pread64_ocall,
		(void*)Enclave_u_readv_ocall,
		(void*)Enclave_u_preadv64_ocall,
		(void*)Enclave_u_write_ocall,
		(void*)Enclave_u_pwrite64_ocall,
		(void*)Enclave_u_writev_ocall,
		(void*)Enclave_u_pwritev64_ocall,
		(void*)Enclave_u_fcntl_arg0_ocall,
		(void*)Enclave_u_fcntl_arg1_ocall,
		(void*)Enclave_u_ioctl_arg0_ocall,
		(void*)Enclave_u_ioctl_arg1_ocall,
		(void*)Enclave_u_close_ocall,
		(void*)Enclave_u_malloc_ocall,
		(void*)Enclave_u_free_ocall,
		(void*)Enclave_u_mmap_ocall,
		(void*)Enclave_u_munmap_ocall,
		(void*)Enclave_u_msync_ocall,
		(void*)Enclave_u_mprotect_ocall,
		(void*)Enclave_u_open_ocall,
		(void*)Enclave_u_open64_ocall,
		(void*)Enclave_u_fstat_ocall,
		(void*)Enclave_u_fstat64_ocall,
		(void*)Enclave_u_stat_ocall,
		(void*)Enclave_u_stat64_ocall,
		(void*)Enclave_u_lstat_ocall,
		(void*)Enclave_u_lstat64_ocall,
		(void*)Enclave_u_lseek_ocall,
		(void*)Enclave_u_lseek64_ocall,
		(void*)Enclave_u_ftruncate_ocall,
		(void*)Enclave_u_ftruncate64_ocall,
		(void*)Enclave_u_truncate_ocall,
		(void*)Enclave_u_truncate64_ocall,
		(void*)Enclave_u_fsync_ocall,
		(void*)Enclave_u_fdatasync_ocall,
		(void*)Enclave_u_fchmod_ocall,
		(void*)Enclave_u_unlink_ocall,
		(void*)Enclave_u_link_ocall,
		(void*)Enclave_u_rename_ocall,
		(void*)Enclave_u_chmod_ocall,
		(void*)Enclave_u_readlink_ocall,
		(void*)Enclave_u_symlink_ocall,
		(void*)Enclave_u_realpath_ocall,
		(void*)Enclave_u_mkdir_ocall,
		(void*)Enclave_u_rmdir_ocall,
		(void*)Enclave_u_opendir_ocall,
		(void*)Enclave_u_readdir64_r_ocall,
		(void*)Enclave_u_closedir_ocall,
		(void*)Enclave_u_dirfd_ocall,
		(void*)Enclave_u_fstatat64_ocall,
		(void*)Enclave_u_getaddrinfo_ocall,
		(void*)Enclave_u_freeaddrinfo_ocall,
		(void*)Enclave_u_gai_strerror_ocall,
		(void*)Enclave_u_socket_ocall,
		(void*)Enclave_u_socketpair_ocall,
		(void*)Enclave_u_bind_ocall,
		(void*)Enclave_u_listen_ocall,
		(void*)Enclave_u_accept_ocall,
		(void*)Enclave_u_accept4_ocall,
		(void*)Enclave_u_connect_ocall,
		(void*)Enclave_u_recv_ocall,
		(void*)Enclave_u_recvfrom_ocall,
		(void*)Enclave_u_recvmsg_ocall,
		(void*)Enclave_u_send_ocall,
		(void*)Enclave_u_sendto_ocall,
		(void*)Enclave_u_sendmsg_ocall,
		(void*)Enclave_u_getsockopt_ocall,
		(void*)Enclave_u_setsockopt_ocall,
		(void*)Enclave_u_getsockname_ocall,
		(void*)Enclave_u_getpeername_ocall,
		(void*)Enclave_u_shutdown_ocall,
		(void*)Enclave_u_poll_ocall,
		(void*)Enclave_u_epoll_create1_ocall,
		(void*)Enclave_u_epoll_ctl_ocall,
		(void*)Enclave_u_epoll_wait_ocall,
		(void*)Enclave_sgx_oc_cpuidex,
		(void*)Enclave_sgx_thread_wait_untrusted_event_ocall,
		(void*)Enclave_sgx_thread_set_untrusted_event_ocall,
		(void*)Enclave_sgx_thread_setwait_untrusted_events_ocall,
		(void*)Enclave_sgx_thread_set_multiple_untrusted_events_ocall,
		(void*)Enclave_u_sgxprotectedfs_exclusive_file_open,
		(void*)Enclave_u_sgxprotectedfs_check_if_file_exists,
		(void*)Enclave_u_sgxprotectedfs_fread_node,
		(void*)Enclave_u_sgxprotectedfs_fwrite_node,
		(void*)Enclave_u_sgxprotectedfs_fclose,
		(void*)Enclave_u_sgxprotectedfs_fflush,
		(void*)Enclave_u_sgxprotectedfs_remove,
		(void*)Enclave_u_sgxprotectedfs_recovery_file_open,
		(void*)Enclave_u_sgxprotectedfs_fwrite_recovery_node,
		(void*)Enclave_u_sgxprotectedfs_do_file_recovery,
		(void*)Enclave_u_getenv_ocall,
	}
};
sgx_status_t ecall_allocate(sgx_enclave_id_t eid, EnclaveBuffer* retval, const uint8_t* buffer, uintptr_t length)
{
	sgx_status_t status;
	ms_ecall_allocate_t ms;
	ms.ms_buffer = buffer;
	ms.ms_length = length;
	status = sgx_ecall(eid, 0, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t ecall_init_bootstrap(sgx_enclave_id_t eid, sgx_status_t* retval, uint8_t* seed)
{
	sgx_status_t status;
	ms_ecall_init_bootstrap_t ms;
	ms.ms_seed = seed;
	status = sgx_ecall(eid, 1, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t ecall_key_gen(sgx_enclave_id_t eid, sgx_status_t* retval, uint8_t* public_key)
{
	sgx_status_t status;
	ms_ecall_key_gen_t ms;
	ms.ms_public_key = public_key;
	status = sgx_ecall(eid, 2, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t ecall_get_attestation_report(sgx_enclave_id_t eid, sgx_status_t* retval)
{
	sgx_status_t status;
	ms_ecall_get_attestation_report_t ms;
	status = sgx_ecall(eid, 3, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t ecall_authenticate_new_node(sgx_enclave_id_t eid, NodeAuthResult* retval, const uint8_t* cert, uintptr_t cert_len, uint8_t* seed)
{
	sgx_status_t status;
	ms_ecall_authenticate_new_node_t ms;
	ms.ms_cert = cert;
	ms.ms_cert_len = cert_len;
	ms.ms_seed = seed;
	status = sgx_ecall(eid, 4, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t ecall_init_node(sgx_enclave_id_t eid, sgx_status_t* retval, const uint8_t* master_cert, uintptr_t master_cert_len, const uint8_t* encrypted_seed, uintptr_t encrypted_seed_len)
{
	sgx_status_t status;
	ms_ecall_init_node_t ms;
	ms.ms_master_cert = master_cert;
	ms.ms_master_cert_len = master_cert_len;
	ms.ms_encrypted_seed = encrypted_seed;
	ms.ms_encrypted_seed_len = encrypted_seed_len;
	status = sgx_ecall(eid, 5, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t ecall_init(sgx_enclave_id_t eid, InitResult* retval, Ctx context, uint64_t gas_limit, uint64_t* used_gas, const uint8_t* contract, uintptr_t contract_len, const uint8_t* env, uintptr_t env_len, const uint8_t* msg, uintptr_t msg_len)
{
	sgx_status_t status;
	ms_ecall_init_t ms;
	ms.ms_context = context;
	ms.ms_gas_limit = gas_limit;
	ms.ms_used_gas = used_gas;
	ms.ms_contract = contract;
	ms.ms_contract_len = contract_len;
	ms.ms_env = env;
	ms.ms_env_len = env_len;
	ms.ms_msg = msg;
	ms.ms_msg_len = msg_len;
	status = sgx_ecall(eid, 6, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t ecall_handle(sgx_enclave_id_t eid, HandleResult* retval, Ctx context, uint64_t gas_limit, uint64_t* used_gas, const uint8_t* contract, uintptr_t contract_len, const uint8_t* env, uintptr_t env_len, const uint8_t* msg, uintptr_t msg_len)
{
	sgx_status_t status;
	ms_ecall_handle_t ms;
	ms.ms_context = context;
	ms.ms_gas_limit = gas_limit;
	ms.ms_used_gas = used_gas;
	ms.ms_contract = contract;
	ms.ms_contract_len = contract_len;
	ms.ms_env = env;
	ms.ms_env_len = env_len;
	ms.ms_msg = msg;
	ms.ms_msg_len = msg_len;
	status = sgx_ecall(eid, 7, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t ecall_query(sgx_enclave_id_t eid, QueryResult* retval, Ctx context, uint64_t gas_limit, uint64_t* used_gas, const uint8_t* contract, uintptr_t contract_len, const uint8_t* msg, uintptr_t msg_len)
{
	sgx_status_t status;
	ms_ecall_query_t ms;
	ms.ms_context = context;
	ms.ms_gas_limit = gas_limit;
	ms.ms_used_gas = used_gas;
	ms.ms_contract = contract;
	ms.ms_contract_len = contract_len;
	ms.ms_msg = msg;
	ms.ms_msg_len = msg_len;
	status = sgx_ecall(eid, 8, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t ecall_run_tests(sgx_enclave_id_t eid, uint32_t* retval)
{
	sgx_status_t status;
	ms_ecall_run_tests_t ms;
	status = sgx_ecall(eid, 9, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t t_global_init_ecall(sgx_enclave_id_t eid, uint64_t id, const uint8_t* path, size_t len)
{
	sgx_status_t status;
	ms_t_global_init_ecall_t ms;
	ms.ms_id = id;
	ms.ms_path = path;
	ms.ms_len = len;
	status = sgx_ecall(eid, 10, &ocall_table_Enclave, &ms);
	return status;
}

sgx_status_t t_global_exit_ecall(sgx_enclave_id_t eid)
{
	sgx_status_t status;
	status = sgx_ecall(eid, 11, &ocall_table_Enclave, NULL);
	return status;
}

